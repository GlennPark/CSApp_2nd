#include "productitem.h"

ProductItem::ProductItem(int id, QString name, int price, int quantity)
{
    setText(0, QString::number(id));
    setText(1, name);
    setText(2, QString::number(price));
    setText(3, QString::number(quantity));
}

QString ProductItem::getName() const
{
    return text(1);
}

void ProductItem::setName(QString& name)
{
    setText(1, name);
}

int ProductItem::getPrice() const
{
    return text(2).toInt();
}

void ProductItem::setPrice(int& price)
{
    setText(2, QString::number(price));
}

int ProductItem::getQuantity() const
{
    return text(3).toInt();
}

void ProductItem::setQuantity(int& quantity)
{
    setText(3, QString::number(quantity));
}

int ProductItem::id() const
{
    return text(0).toInt();
}

// Define copy assignment operator.
bool ProductItem::operator==(const ProductItem &other) const {
    return (this->text(1) == other.text(1));
}
