#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <clientmanagerform.h>
#include <productmanagerform.h>
#include <chatserverform.h>
#include <chatclientform.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class ChatServerForm;
class ChatClientForm;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionClient_triggered();
    void on_actionProduct_triggered();



    void on_actionChatClient_triggered();

    void on_actionChatServer_triggered();

private:
    Ui::MainWindow *ui;
    ClientManagerForm *clientForm;
    ProductManagerForm *productForm;
    ChatClientForm *chatClientForm;
    ChatServerForm *chatServerForm;
};
#endif // MAINWINDOW_H
