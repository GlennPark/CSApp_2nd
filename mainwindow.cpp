#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "clientmanagerform.h"
#include "productmanagerform.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    ClientManagerForm *clientForm1 = new ClientManagerForm(0);
//    clientForm1->show();
    clientForm = new ClientManagerForm(this);
    clientForm->setWindowTitle(tr("Client Enroll"));
    connect(clientForm, SIGNAL(destroyed()),
            clientForm, SLOT(deleteLater()));
//    ui->tabWidget->addTab(clientForm, "&Client Info");

//    ProductManagerForm *productForm = new ProductManagerForm(this);
//    productForm->setWindowTitle(tr("Product Enroll"));

    productForm = new ProductManagerForm(this);
    productForm->setWindowTitle(tr("Product Enroll"));
    connect(productForm, SIGNAL(destroyed()), productForm, SLOT(deleteLater()));


    QMdiSubWindow *cw = ui->mdiArea->addSubWindow(clientForm);
    ui->mdiArea->addSubWindow(productForm);
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
