#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>

QT_BEGIN_NAMESPACE
class QTcpSocket;
class QDataStream;
class QNetworkSession;
QT_END_NAMESPACE

namespace Ui {
  class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = Q_NULLPTR);
  ~MainWindow();

private slots:
  void start();
  void startTransfer();
  void updateClientProgress(qint64);
  void rqMsg(); //requset message
  void readMsg();
  void dpError(QAbstractSocket::SocketError); //display error
  void sessionOpened();

private:
  Ui::MainWindow *ui;
  QTcpSocket* socket;
  QDataStream* in;
  QNetworkSession* session;

  int bytesToWrite;
  int bytesWritten;
  int bytesReceived;
};

#endif // MAINWINDOW_H
