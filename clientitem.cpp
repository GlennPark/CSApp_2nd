#include "clientitem.h"

#include <QLabel>
#include <iostream>

using namespace std;

ClientItem::ClientItem(int Cid, QString name, QString phoneNumber, QString email, QString address, QString favorite, QString age, QString gender)
{
    setText(0, QString::number(Cid));
    setText(1, name);
    setText(2, phoneNumber);
    setText(3, email);
    setText(4, address);
    setText(5, favorite);
    setText(6, age);
    setText(7, gender);
}

QString ClientItem::getName() const
{
    return text(1);
}

void ClientItem::setName(QString& name)
{
    setText(1, name);
}

QString ClientItem::getPhoneNumber() const
{
    return text(2);
}

void ClientItem::setPhoneNumber(QString& phoneNumber)
{
    setText(2, phoneNumber);    // c_str() --> const char*
}

QString ClientItem::getEmail() const
{
    return text(3);
}

void ClientItem::setEmail(QString& email)
{
    setText(3, email);
}

QString ClientItem::getAddress() const
{
    return text(4);
}

void ClientItem::setAddress(QString& address)
{
    setText(4, address);
}

QString ClientItem::getFavorite() const
{
    return text(5);
}

void ClientItem::setFavorite(QString& favorite)
{
    setText(5, favorite);
}

QString ClientItem::getAge() const
{
    return text(6);
}

void ClientItem::setAge(QString& age)
{
    setText(6, age);
}

QString ClientItem::getGender() const
{
    return text(7);
}

void ClientItem::setGender(QString& gender)
{
    setText(7, gender);
}

int ClientItem::Cid() const
{
    return text(0).toInt();
}

// Define copy assignment operator.
bool ClientItem::operator==(const ClientItem &other) const {
    return (this->text(1) == other.text(1));
}
