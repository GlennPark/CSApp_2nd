#include "chatserverform.h"
#include "ui_chatserverform.h"
#include <QtGui>
#include <QtWidgets>
#include <QtNetwork>

#define BLOCK_SIZE 1024

ChatServerForm::ChatServerForm(QWidget *parent)
    : QWidget(parent), ui(new Ui::ChatServerForm)
{
    ui->setupUi(this);


    infoLabel = new QLabel(this);
    QPushButton *quitButton = new QPushButton("Quit", this);
    connect(quitButton, SIGNAL(clicked()), qApp, SLOT(quit()));

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout -> addStretch(1);
    buttonLayout -> addWidget(quitButton);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout -> addWidget(infoLabel);
    mainLayout -> addLayout(buttonLayout);
    setLayout(mainLayout);

    tcpServer = new QTcpServer(this);
    connect(tcpServer, SIGNAL(newConnection()), SLOT(clientConnect()));
    if(!tcpServer ->listen())
    {
        QMessageBox::critical(this, tr("Echo Server"),\
                              tr("Unable to start the server: %1.")\
                              .arg(tcpServer->errorString()));
        close();
        return;
    }

    infoLabel->setText(tr("The server is running on port %1.")
                       .arg(tcpServer->serverPort()));
    setWindowTitle(tr("Echo Server"));

}



void ChatServerForm::chatData()
{
    QTcpSocket *clientConnection = (QTcpSocket *)sender();
    if(clientConnection->bytesAvailable()>BLOCK_SIZE) return;
    QByteArray bytearray = clientConnection->read(BLOCK_SIZE);
//    clientConnection->write(bytearray);
    foreach (QTcpSocket *sock, clientList)
    {
        if(sock != clientConnection)
            sock->write(bytearray);
    }

    infoLabel->setText(QString(bytearray));
}
void ChatServerForm::removeItem()
{
    QTcpSocket *clientConnection = dynamic_cast<QTcpSocket *>(sender( ));
    clientList.removeOne(clientConnection);
    clientConnection->deleteLater();
}

void ChatServerForm::clientConnect( )
{
    QTcpSocket *clientConnection = tcpServer->nextPendingConnection( );
    connect(clientConnection, SIGNAL(readyRead( )), SLOT(echoData( )));
    connect(clientConnection, SIGNAL(disconnected( )), SLOT(removeItem()));
    infoLabel->setText("new connection is established...");

    clientList.append(clientConnection);        // QList<QTcpSocket*> clientList;
}
ChatServerForm::~ChatServerForm()
{
    delete ui;
}

