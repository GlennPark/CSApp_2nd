#ifndef CLIENTITEM_H
#define CLIENTITEM_H

#include <QTreeWidgetItem>

class ClientItem : public QTreeWidgetItem
{
public:
    explicit ClientItem(int Cid = 0, QString = "", QString = "", QString = "", QString = "", QString = "", QString = "", QString = "" );


    QString getName() const;
    void setName(QString&);
    QString getPhoneNumber() const;
    void setPhoneNumber(QString&);
    QString getEmail() const;
    void setEmail(QString&);
    QString getAddress() const;
    void setAddress(QString&);
    QString getFavorite() const;
    void setFavorite(QString&);

    QString getGender() const;
    void setGender(QString&);

    QString getAge() const;
    void setAge(QString&);


    int Cid() const;

    bool operator==(const ClientItem &other) const;
};

#endif // CLIENTITEM_H
