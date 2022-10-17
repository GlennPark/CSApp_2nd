#ifndef CHATCLIENTFORM_H
#define CHATCLIENTFORM_H

#include <QMainWindow>
#include <QWidget>
#include <QLabel>
#include <QTextEdit>
#include <QLineEdit>
#include <QTcpSocket>
#include <QApplication>

QT_BEGIN_NAMESPACE
namespace Ui { class ChatClientForm; }
QT_END_NAMESPACE

class ChatClientForm : public QWidget
{
    Q_OBJECT
public:
    ChatClientForm(QWidget *parent = nullptr);
    ~ChatClientForm();
signals:

private slots:
    void chatData();
    void sendChatData();

private:
    Ui::ChatClientForm *ui;
    QTextEdit *message;
    QLineEdit *inputLine;
    QTcpSocket *clientSocket;

};

#endif // CHATCLIENTFORM_H
