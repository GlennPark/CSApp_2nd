#ifndef CUSTOMERSEARCH_H
#define CUSTOMERSEARCH_H


#include "clientitem.h"
#include "clientmanagerform.h"


namespace Ui {
class CustomerSearch;
}


class CustomerSearch : public QWidget
{
    Q_OBJECT

public slots:


public:
    explicit CustomerSearch(QWidget *parent = nullptr);


signals:
private:
        Ui::ClientManagerForm *ui;

};

#endif // CUSTOMERSEARCH_H
