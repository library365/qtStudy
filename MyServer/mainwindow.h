#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork>

namespace Ui {
  class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

public slots:
    void start();
    void acceptConnection();
    void startTransfer();
    void updateProgress();
    void handleSocketError(QAbstractSocket::SocketError);

private:
  QTcpServer tcpServer;
  QTcpSocket* tcpServerSocket;

  int bytesToWrite;
  int bytesWritten;
  int bytesReceived;

  Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
