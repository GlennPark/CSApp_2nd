#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class ClientManagerForm;
class ProductManagerForm;
class OrderManagerForm;
class ChatServerForm;
class ChatClientForm;
class CustomerSearch;
class MerchandiseSearch;
class PurchaseSearch;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionClient_triggered();
    void on_actionProduct_triggered();
    void on_actionOrder_triggered();
    void on_actionChatting_triggered();
   void on_customerChatAction_triggered();
    void on_customerSearchAction_triggered();




private:
    Ui::MainWindow *ui;
    ClientManagerForm *clientForm;
    ProductManagerForm *productForm;
    OrderManagerForm* orderForm;
    ChatServerForm* chatServerForm;
    ChatClientForm* chatClientForm;
    CustomerSearch* customerSearch;
    MerchandiseSearch* merchandiseSearch;
    PurchaseSearch* purchaseSearch;
};
#endif // MAINWINDOW_H
