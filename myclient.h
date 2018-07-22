#ifndef _MyClient_h_
#define _MyClient_h_


#include "backend.h"
#include <QWidget>
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QDataStream>
#include <QTime>
#include <QHBoxLayout>
#include <QSslSocket>
#include <QString>
#include <QSettings>


#include <QDataStream>
#include <QByteArray>



class QTextEdit;
class QLineEdit;

// ======================================================================
class MyClient : public QWidget {
    Q_OBJECT
public:
    // Q_PROPERTY(QString input WRITE setInputValue
    //                          READ inputValue
    //                          NOTIFY inputValueChanged)

    QSslSocket* m_pTcpSocket;
    QString m_ptxtInfo;
    QString m_ptxtInput;
    quint16 m_nNextBlockSize;
    QString idNumber, balance, state, pay_day, paket;
    QString payments;
    int Port;
    QVector<QString> times_vct, cashes_vct, comments_vct;

    QSettings dataSet;
    QString enteredName;
    QString enteredPass;
    QString loginResult = "По каким то причинам<br>не удается войти в систему.<br>"
                          "Проверьте сетевое подключение.";
    bool isAuthOk = false;        ///////////////////// ?
    bool isConnect = false;
    bool demo = false;



    MyClient(QWidget* pwgt = 0);
    void Sender(const QString& msg);
    void connectToHost();
    Q_INVOKABLE void setAuthData(QString name, QString pass);




public slots:
    bool isAuth();
    QString authResult();
    bool isAuthRight();
    void quitAndClear();
    void showPayments();
    void askForPayments();
    void askForTrustedPay();
    bool showDemo();
    int payTableLenght();


    QString givePayTime(int strN);
    QString givePayCash(int strN);
    QString givePayComm(int strN);



    void slotReadyRead();
    void slotConnected();
    void slotError(QAbstractSocket::SocketError);
    QString showPlan();
    QString showBill();
    QString showId();
    QString showPay_day();
    QString showState();
    void setAuthOn();
    void setAuthNo();





};
#endif  //_MyClient_h_
