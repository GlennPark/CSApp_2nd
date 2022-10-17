#include "clientmanagerform.h"
#include "ui_clientmanagerform.h"
#include "clientitem.h"

#include <QFile>
#include <QMenu>

ClientManagerForm::ClientManagerForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClientManagerForm)
{
    ui->setupUi(this);

    QList<int> sizes;
    sizes << 600 << 500;
//    ui->splitter->setSizes(sizes);

    QAction* removeAction = new QAction(tr("&Remove"));
    connect(removeAction, SIGNAL(triggered()), SLOT(removeItem()));

    menu = new QMenu;
    menu->addAction(removeAction);
    ui->treeWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->treeWidget, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(showContextMenu(QPoint)));

    connect(ui->searchLineEdit, SIGNAL(returnPressed()),
            this, SLOT(on_searchPushButton_clicked()));

    QFile file("clientlist.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QList<QString> row = line.split(", ");
        if(row.size()) {
            int id = row[0].toInt();
            ClientItem* c = new ClientItem(id, row[1], row[2], row[3], row[4], row[5], row[6], row[7]);
            ui->treeWidget->addTopLevelItem(c);
            clientList.insert(id, c);
        }
    }
    file.close( );
}

ClientManagerForm::~ClientManagerForm()
{
    delete ui;

    QFile file("clientlist.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream out(&file);
    for (const auto& v : clientList) {
        ClientItem* c = v;
        out << c->Cid() << ", " << c->getName() << ", ";
        out << c->getPhoneNumber() << ", ";
        out << c->getEmail() << ", ";
        out << c->getAddress() << ", ";
        out << c->getFavorite() << ", ";
        out << c->getAge() << ", ";
        out << c->getGender() << "\n";

    }
    file.close( );
}

int ClientManagerForm::makeCid( )
{
    if(clientList.size( ) == 0) {
        return 100;
    } else {
        auto Cid = clientList.lastKey();
        return ++Cid;
    }
}

void ClientManagerForm::removeItem()
{
    QTreeWidgetItem* item = ui->treeWidget->currentItem();
    if(item != nullptr) {
        clientList.remove(item->text(0).toInt());
        ui->treeWidget->takeTopLevelItem(ui->treeWidget->indexOfTopLevelItem(item));
//        delete item;
        ui->treeWidget->update();
    }
}

void ClientManagerForm::showContextMenu(const QPoint &pos)
{
    QPoint globalPos = ui->treeWidget->mapToGlobal(pos);
    menu->exec(globalPos);
}

void ClientManagerForm::on_searchPushButton_clicked()
{
    ui->searchTreeWidget->clear();
//    for(int i = 0; i < ui->treeWidget->columnCount(); i++)
    int i = ui->searchComboBox->currentIndex();
    auto flag = (i)? Qt::MatchCaseSensitive|Qt::MatchContains
                   : Qt::MatchCaseSensitive;
    {
        auto items = ui->treeWidget->findItems(ui->searchLineEdit->text(), flag, i);

        foreach(auto i, items) {
            ClientItem* c = static_cast<ClientItem*>(i);
            int id = c->Cid();
            QString name = c->getName();
            QString number = c->getPhoneNumber();
            QString email = c->getEmail();
            QString address = c->getAddress();
            QString favorite = c->getFavorite();
            QString age = c->getAge();
            QString gender = c->getGender();
            ClientItem* item = new ClientItem(id, name, number, email, address, favorite, age, gender);
            ui->searchTreeWidget->addTopLevelItem(item);
        }
    }
}

void ClientManagerForm::on_modifyPushButton_clicked()
{
    QTreeWidgetItem* item = ui->treeWidget->currentItem();
    if(item != nullptr) {
        int key = item->text(0).toInt();
        ClientItem* c = clientList[key];
        QString name, number,  email, address, favorite, age, gender;
        name = ui->nameLineEdit->text();
        number = ui->phoneNumberLineEdit->text();
        email = ui->emaillineEdit->text();
        address = ui->addressLineEdit->text();
        favorite = ui->addressLineEdit->text();
        age = ui->AgeSpinBox->text();
        gender = ui->MaleButton->text();
        c->setName(name);
        c->setPhoneNumber(number);
        c->setEmail(email);
        c->setAddress(address);
        c->setFavorite(favorite);
        c->setAge(age);
        c->setGender(gender);
        clientList[key] = c;
    }
}

void ClientManagerForm::on_addPushButton_clicked()
{
    QString name, number, email, address, favorite, age, gender;
    int Cid = makeCid();
    name = ui->nameLineEdit->text();
    number = ui->phoneNumberLineEdit->text();
    email = ui->emaillineEdit->text();
    address = ui->addressLineEdit->text();
    favorite = ui->addressLineEdit->text();
    age = ui->AgeSpinBox->text();
    gender = ui->MaleButton->text();
    if(name.length()) {
        ClientItem* c = new ClientItem(Cid, name, number, email, address, favorite, age, gender);
        clientList.insert(Cid, c);
        ui->treeWidget->addTopLevelItem(c);
    }
}

void ClientManagerForm::on_treeWidget_itemClicked(QTreeWidgetItem *item, int column)
{
    Q_UNUSED(column);
    ui->idLineEdit->setText(item->text(0));
    ui->nameLineEdit->setText(item->text(1));
    ui->phoneNumberLineEdit->setText(item->text(2));
    ui->addressLineEdit->setText(item->text(3));
}

void ClientManagerForm::on_ClientManagerForm_destroyed()
{}



