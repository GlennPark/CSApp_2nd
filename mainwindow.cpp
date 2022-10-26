#include "mainwindow.h"
#include "customersearch.h"
#include "merchandisesearch.h"
#include "purchasesearch.h"
#include "ui_mainwindow.h"


#include "clientmanagerform.h"

#include "productmanagerform.h"
#include "ordermanagerform.h"
#include "chatserverform.h"
#include "chatclientform.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
//  MainWindow::setWindowFlags(Qt::Window | Qt::FramelessWindowHint);






    customerSearch = new CustomerSearch(this);

    merchandiseSearch = new MerchandiseSearch(this);

    purchaseSearch = new PurchaseSearch(this);


    clientForm = new ClientManagerForm(this);
    QMdiSubWindow *cw = ui->mdiArea->addSubWindow(clientForm);
    clientForm->loadData();
    clientForm->setWindowTitle(tr("Client Info"));
    clientForm->setWindowFlags(Qt::FramelessWindowHint);
    clientForm->showMaximized();

    connect(clientForm, SIGNAL(destroyed()),clientForm, SLOT(deleteLater()));
    connect(clientForm, SIGNAL(clientAdded(int, QString)),orderForm, SLOT(addClient(int, QString)));
    connect(clientForm, SIGNAL(sendClientInfo(QString, QString, QString, QString, QString, QString, QString, QString)),orderForm,SLOT(getClientInfo(QString,QString,QString)));
    connect(clientForm, SIGNAL(clientAdded(int, QString)),chatServerForm,SLOT(addClient(int, QString)));

    productForm = new ProductManagerForm(this);
    ui->mdiArea->addSubWindow(productForm);
    productForm->loadData();
    productForm->setWindowTitle(tr("Product Info"));
    productForm->setWindowFlag(Qt::FramelessWindowHint);
    productForm->showMaximized();

    connect(productForm, SIGNAL(destroyed()),productForm, SLOT(deleteLater()));
    connect(productForm, SIGNAL(productAdded(int, QString)),orderForm, SLOT(addProduct(int, QString)));
    connect(productForm, SIGNAL(sendProductInfo(QString, int, int)),orderForm, SLOT(getProductInfo(QString, int, int)));

    orderForm = new OrderManagerForm(this);
    ui->mdiArea->addSubWindow(orderForm);
    orderForm->loadData();
    orderForm->setWindowTitle(tr("Order Info"));
    orderForm->setWindowFlag(Qt::FramelessWindowHint);
    orderForm->showMaximized();

    connect(orderForm, SIGNAL(destroyed()),orderForm, SLOT(deleteLater()));
    connect(orderForm, SIGNAL(getClientInfo(int)),clientForm, SLOT(acceptClientInfo(int)));
    connect(orderForm, SIGNAL(getProductInfo(int)),productForm, SLOT(acceptProductInfo(int)));

    ui->setupUi(this);

    chatServerForm = new ChatServerForm(this);
    ui->mdiArea->addSubWindow(chatServerForm);
    chatServerForm->setWindowTitle(tr("Chatting Server"));
    chatServerForm->setWindowFlags(Qt::FramelessWindowHint);
    chatServerForm->showMaximized();

    connect(chatServerForm, SIGNAL(destroyed()), chatServerForm, SLOT(deleteLater()));

    chatClientForm = new ChatClientForm(this);
    ui->mdiArea->addSubWindow(chatClientForm);
    chatClientForm->setWindowTitle(tr("Chatting Client"));
    chatClientForm->setWindowFlags(Qt::FramelessWindowHint);
    chatClientForm->showMaximized();

    connect(chatClientForm, SIGNAL(destroyed()), chatClientForm, SLOT(deleteLater()));

    ui->mdiArea->setActiveSubWindow(cw);
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

void MainWindow::on_actionOrder_triggered()
{
    if(orderForm != nullptr)
    {
        orderForm->setFocus();
    }
}


void MainWindow::on_actionChatting_triggered()
{
    if(chatServerForm != nullptr)
    {
        chatServerForm->setFocus();
    }
}


void MainWindow::on_customerChatAction_triggered()
{
    if(chatClientForm != nullptr)
    {
        chatClientForm->setFocus();
    }
}


void MainWindow::on_customerSearchAction_triggered()
{
    if(customerSearch != nullptr)
    {
        customerSearch->setFocus();
    }
}








