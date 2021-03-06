#ifndef CLIENTTHREAD_H
#define CLIENTTHREAD_H
#include <QThread>
#include <QtCore>
#include <QTcpSocket>

class ClientThread : public QThread
{
    Q_OBJECT

protected:
    void run();
public:
    ClientThread();
public slots:
    void read_Data();
    void receiveConnected();
    void receiveConnectedError(QTcpSocket::SocketError socketError);
    void receiveAddData(const QString& addData);
    //线程之间传递数据的引用要加const
    void sendData(const QString& start,const QString& end);
signals:
    void changeRouteText(const QString &);
private:
    QString m_addr;
    int m_port;
    QTcpSocket *m_tcpClient;
    QHash<QTcpSocket*, QByteArray*> buffers;

};
#endif // CLIENTTHREAD_H
