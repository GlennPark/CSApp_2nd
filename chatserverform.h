#ifndef CHATSERVERFORM_H
#define CHATSERVERFORM_H

#include <QMainWindow>
#include <QWidget>
#include <QLabel>

#include <QTextEdit>
#include <QPushButton>
#include <QTcpServer>
#include <QTcpSocket>
#include <QApplication>



QT_BEGIN_NAMESPACE
namespace Ui { class ChatServerForm; }
QT_END_NAMESPACE

class ChatServerForm : public QWidget
{
    Q_OBJECT
public:
    ChatServerForm(QWidget *parent = nullptr);
    ~ChatServerForm();
signals:

private slots:
    void clientConnect();
    void chatData();
    void removeItem();
private:
    Ui::ChatServerForm *ui;
    QLabel *infoLabel;
    QTcpServer *tcpServer;
    QList<QTcpSocket*> clientList;

};

#endif // CHATSERVERFORM_H
