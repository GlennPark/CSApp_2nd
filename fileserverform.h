#ifndef FILESERVERFORM_H
#define FILESERVERFORM_H

#include <QObject>
#include <QWidget>


class QLabel;
class QTcpServer;
class QTcpSocket;
class QFile;
class QProgressDialog;


typedef enum {
    file_transform
} file_status;

typedef struct {
    int type;
    char data[1020];
} fileProtocolType;

class FileServerForm : public QWidget
{
    Q_OBJECT

public:
    explicit FileServerForm(QWidget *parent = nullptr);
    ~FileServerForm();
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

public slots:

    //파일 입출력 슬롯함수
    void acceptConnection();
    void readClient();
    void clickButton();


signals:

};

#endif // FILESERVERFORM_H
