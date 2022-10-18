#ifndef CHATSERVERFORM_H
#define CHATSERVERFORM_H

#include <QWidget>
#include <QList>
#include <QHash>

//네크워크 공용
class QLabel;
class QTcpServer;
class QTcpSocket;

//파일 입출력
class QFile;
class QProgressDialog;


namespace Ui {
class ChatServerForm;
}

typedef struct {
    int type;
    char data[1020];
} chatProtocolType;

typedef enum {
    Chat_Login,
    Chat_In,
    Chat_Talk,
    Chat_Close,
    Chat_LogOut,
    Chat_Invite,
    Chat_KickOut,
    Chat_FileTransform
} Chat_Status;

class ChatServerForm : public QWidget
{
    Q_OBJECT

public:
    explicit ChatServerForm(QWidget *parent = nullptr);
    ~ChatServerForm();

    //파일 입출력 멤버변수
    QLabel *infoLabel;
    QTcpServer *server;
    QTcpSocket *receivedSocket;
    QFile *newFile;
    QProgressDialog *progressDialog;

    QByteArray inBlock;
    QString filename;
    qint64 totalSize;
    qint64 byteReceived;

private:
    const int BLOCK_SIZE = 1024;
    Ui::ChatServerForm *ui;
    QTcpServer *tcpServer;
    QList<QTcpSocket*> clientList;
    QList<int> clientIDList;
    QHash<QString, QString> clientNameHash;
    QHash<QString, int> clientIDHash;
    QMenu* menu;



private slots:
    //ui
    void clientConnect( );                       /* 채팅 서버 */
    void receiveData( );
    void removeClient( );
    void addClient(int, QString);
    void inviteClient();
    void kickOut();
    void on_clientTreeWidget_customContextMenuRequested(const QPoint &pos);

    //파일 입출력 슬롯함수
    void acceptConnection();
    void readClient();
    void clickButton();
};
#endif // CHATSERVERFORM_H
