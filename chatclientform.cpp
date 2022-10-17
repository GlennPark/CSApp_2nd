#include "chatclientform.h"
#include "ui_chatclientform.h"
#include <QtGui>
#include <QtWidgets>
#include <QtNetwork>


#define BLOCK_SIZE 1024

ChatClientForm::ChatClientForm(QWidget *parent)
    : QWidget(parent), ui(new Ui::ChatClientForm)
{
    ui->setupUi(this);

    QLineEdit *serverAddress = new QLineEdit(this);
    serverAddress->setText("127.0.0.1");

    QRegularExpression re("^(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\."
                          "(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\."
                          "(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\."
                          "(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$|");
    QRegularExpressionValidator validator(re);
    serverAddress->setPlaceholderText("Server IP Address");

    QLineEdit *serverPort = new QLineEdit(this);
    serverPort->setInputMask("00000;_");
    serverPort->setPlaceholderText("Server Port No");

    QPushButton *connectButton = new QPushButton("connect", this);
    connect(connectButton, &QPushButton::clicked,[=]{clientSocket->connectToHost(serverAddress->text(),serverPort->text().toInt());});

    QHBoxLayout *serverLayout = new QHBoxLayout;
    serverLayout->addStretch(0);
    serverLayout->addWidget(serverAddress);
    serverLayout->addWidget(serverPort);
    serverLayout->addWidget(connectButton);

    message = new QTextEdit(this);
    message->setReadOnly(true);

    inputLine = new QLineEdit(this);
    QPushButton *sentButton = new QPushButton("Send", this);
    connect(sentButton, SIGNAL(clicked()),SLOT(sendChatData()));

    QHBoxLayout *inputLayout = new QHBoxLayout;

//    inputLine = new QLineEdit(this);
//        connect(inputLine, SIGNAL(returnPressed()), SLOT(sendChatData()));
//        connect(inputLine, SIGNAL(returnPressed()), inputLine, SLOT(clear()));


    QPushButton *quitButton = new QPushButton("Quit", this);
    connect(quitButton, SIGNAL(clicked()),qApp,SLOT(quit()));

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addStretch(1);
    buttonLayout->addWidget(quitButton);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(serverLayout);
    mainLayout->addWidget(message);
    mainLayout->addLayout(inputLayout);
    mainLayout->addLayout(buttonLayout);

    setLayout(mainLayout);
    clientSocket = new QTcpSocket(this);
    connect(clientSocket, &QAbstractSocket::errorOccurred,[=]{qDebug()<<clientSocket->errorString();});
    connect(clientSocket, SIGNAL(readyRead()), SLOT(chatData()));
    setWindowTitle(tr("Chat Client"));
}



ChatClientForm::~ChatClientForm()
{
    delete ui;
    clientSocket->close();
}

void ChatClientForm::chatData()
{
    QTcpSocket *clientSocket = dynamic_cast<QTcpSocket *>(sender());
    if(clientSocket->bytesAvailable() > BLOCK_SIZE) return;
    QByteArray bytearray = clientSocket->read(BLOCK_SIZE);
    message->append(QString(bytearray));
}

void ChatClientForm::sendChatData()
{
    QString str = inputLine->text( );
    if(str.length( )) {
    QByteArray bytearray;
    bytearray = str.toUtf8( );
    clientSocket->write(bytearray);
    message->append(QString(bytearray));
    }

}
