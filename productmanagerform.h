#ifndef PRODUCTMANAGERFORM_H
#define PRODUCTMANAGERFORM_H

#include <QWidget>
#include "productitem.h"
namespace Ui {
class ProductManagerForm;
}

class ProductManagerForm : public QWidget
{
    Q_OBJECT

public:
    explicit ProductManagerForm(QWidget *parent = nullptr);
    ~ProductManagerForm();

private:
    Ui::ProductManagerForm *ui;
    QMap<int, ProductItem*> productList;
};

#endif // PRODUCTMANAGERFORM_H
