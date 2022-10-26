#ifndef PURCHASESEARCH_H
#define PURCHASESEARCH_H

#include <QMainWindow>
#include "orderitem.h"
#include "ordermanagerform.h"
#include "ui_ordermanagerform.h"

class PurchaseSearch : public QWidget
{
    Q_OBJECT
public:
    explicit PurchaseSearch(QWidget *parent = nullptr);
};

#endif // PURCHASESEARCH_H
