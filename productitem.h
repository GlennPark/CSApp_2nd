#ifndef PRODUCTITEM_H
#define PRODUCTITEM_H

#include <QTreeWidgetItem>

class ProductItem : public QTreeWidgetItem
{
public:
    explicit ProductItem(int id = 0, QString = "", int = 0, int = 0);

    QString getName() const;
    void setName(QString&);
    int getPrice() const;
    void setPrice(int&);
    int getQuantity() const;
    void setQuantity(int&);
    int id() const;
    bool operator==(const ProductItem &other) const;
};

#endif // PRODUCTITEM_H
