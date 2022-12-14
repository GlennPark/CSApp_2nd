#ifndef CHATCLIENTFORM_H
#define CHATCLIENTFORM_H

#include <QWidget>
#include "chatserverform.h"

class QTextEdit;
class QLineEdit;
class QTcpSocket;
class QPushButton;
class QFile;
class QProgressDialog;
class QMessageBox;

namespace  Ui {
class ChatClientForm;
}

class ChatClientForm : public QWidget
{
    Q_OBJECT
public:
    ChatClientForm();

public:
    const int PORT_NUMBER = 8400;

    ChatClientForm(QWidget *parent = nullptr);
    ~ChatClientForm();

private slots:
    void receiveData( );			// 서버에서 데이터가 올 때
    void sendData( );               // 서버로 데이터를 보낼 때
    void disconnect( );
    void sendProtocol(Chat_Status, char*, int = 1020);
    void sendFile();
    void goOnSend(qint64);

private:
    void closeEvent(QCloseEvent*) override;

    QLineEdit *name;                // ID(이름)을 입력하는 창
    QTextEdit *message;             // 서버에서 오는 메세지 표시용
    QLineEdit* serverAddress;
    QLineEdit* serverPort;
    QLineEdit *inputLine;           // 서버로 보내는 메시지 입력용
    QPushButton *connectButton;     // 서버 로그인 등 접속 처리
    QPushButton *sentButton;        // 메시지 전송
    QPushButton* fileButton;        // 파일 전송
    QTcpSocket *clientSocket;		// 클라이언트용 소켓
    QTcpSocket *fileClient;
    QProgressDialog* progressDialog;    // 파일 진행 확인
    QFile* file;                        // 서버로 보내는 파일
    qint64 loadSize;
    qint64 byteToWrite;
    qint64 totalSize;
    QByteArray outBlock;
    QMessageBox *male;
    QMessageBox *female;
    bool isSent;
};

#endif // CHATCLIENTFORM_H
