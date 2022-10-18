#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "clientmanagerform.h"
#include "productmanagerform.h"
#include "chatserverform.h"
#include "chatclientform.h"
#include <QAction>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    clientForm = new ClientManagerForm(this);
    clientForm->setWindowTitle(tr("Client Enroll"));
    ui->mdiArea->addSubWindow(clientForm);
    connect(clientForm, SIGNAL(destroyed()), clientForm, SLOT(deleteLater()));

    productForm = new ProductManagerForm(this);
    productForm->setWindowTitle(tr("Product Enroll"));
    ui->mdiArea->addSubWindow(productForm);
    connect(productForm, SIGNAL(destroyed()), productForm, SLOT(deleteLater()));

    chatClientForm = new ChatClientForm(0);
    chatClientForm->setWindowTitle(tr("Chat Client Form"));
    ui->mdiArea->addSubWindow(chatClientForm);
    connect(chatClientForm, SIGNAL(destroyed()), chatClientForm, SLOT(deleteLater()));
//    chatClientForm->show();


   // connect(,SIGNAL(triggered()), chatClientForm, SLOT(on_actionChatClient_triggered()));


    chatServerForm = new ChatServerForm(0);
    chatServerForm->setWindowTitle(tr("Chat Server Form"));
//    chatServerForm->show();
    ui->mdiArea->addSubWindow(chatServerForm);

    connect(chatServerForm, SIGNAL(destroyed()), chatServerForm, SLOT(deleteLater()));

    fileClientForm = new FileClientForm(0);
    fileClientForm->setWindowTitle;

    clientForm->showMaximized();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionClient_triggered()
{
    if(clientForm != nullptr)
    {
        clientForm->setFocus();
    }
}

void MainWindow::on_actionProduct_triggered()
{
    if(productForm != nullptr)
    {
        productForm->setFocus();
    }
}


void MainWindow::on_actionChatClient_triggered()
{
    if(chatClientForm != nullptr)
    {
        chatClientForm->setFocus();
    }
}


void MainWindow::on_actionChatServer_triggered()
{
    if(chatServerForm != nullptr)
    {
        chatServerForm->setFocus();
    }
}


void MainWindow::on_actionFileTransfer_triggered()
{
    if(fileClientForm != nullptr)
    {
        fileClientForm->setFocus();
    }

}

