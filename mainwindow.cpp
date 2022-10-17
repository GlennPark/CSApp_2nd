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
    ui->mdiArea->addSubWindow(chatClientForm);
//    chatClientForm->show();
    chatClientForm->setWindowTitle(tr("Chat Client Form"));
    connect(chatClientForm, SIGNAL(destroyed()), chatClientForm, SLOT(deleteLater()));
   // connect(,SIGNAL(triggered()), chatClientForm, SLOT(on_actionChatClient_triggered()));


    chatServerForm = new ChatServerForm(0);
//    chatServerForm->show();
    ui->mdiArea->addSubWindow(chatServerForm);
    chatServerForm->setWindowTitle(tr("Chat Server Form"));
    connect(chatServerForm, SIGNAL(destroyed()), chatServerForm, SLOT(deleteLater()));



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

