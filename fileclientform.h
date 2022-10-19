#ifndef FILECLIENTFORM_H
#define FILECLIENTFORM_H


#include <QWidget>

class QTcpSocket;
class QFile;
class QProgressDialog;
class QLabel;


class FileClientForm : public QWidget
{
    Q_OBJECT

public:
    explicit FileClientForm(QWidget *parent = nullptr);
    ~FileClientForm();

    QLabel* infoLabel;
    QTcpSocket *tcpClient;
    QFile *localFile;
    QString filename;
    QByteArray outBlock;
    qint64 loadSize;
    qint64 byteToWrite;
    qint64 totalSize;

    int sendTimes;
    QProgressDialog* progressDialog;

public slots:
    void send();
    void goOnSend(qint64);
    void openFile();
    void sendData();



};
#endif // FILECLIENTFORM_H
