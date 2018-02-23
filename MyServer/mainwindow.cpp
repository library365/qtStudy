#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>

static const int TotalBytes = 50 * 1024 * 1024;
static const int PayloadSize = 64 * 1024; // 64 KB

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  connect(ui->btnStart,SIGNAL(released()),SLOT(start()));
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::start()
{
  ui->btnStart->setEnabled(false);

  bytesWritten = 0;
  bytesReceived = 0;

  //서버가 연결대기중이 아님 && 연결대기 불가 이면 반복
  while(!tcpServer.isListening() && !tcpServer.listen()){
    QMessageBox::StandardButton ret = QMessageBox::critical(this
                                                            , tr("My server"), tr("Unable to start the test: %1.").arg(tcpServer.errorString())
                                                            , QMessageBox::Retry | QMessageBox::Cancel);
    if(QMessageBox::Cancel == ret) return;
  }

  connect(&tcpServer, SIGNAL(newConnection()), SLOT(acceptConnection()));
  ui->labelState->setText(tr("Listening port : %2").arg(tcpServer.serverPort()));
}

void MainWindow::acceptConnection()
{
  tcpServerSocket = tcpServer.nextPendingConnection();

  connect(tcpServerSocket, SIGNAL(readyRead()), SLOT(updateProgress()));
  //connect(tcpServerConnection, SIGNAL(error(QAbstractSocket::SocketError)),
  //  this, SLOT(displayError(QAbstractSocket::SocketError)));

  ui->labelState->setText(tr("CONNECTION ACCEPTED"));
  tcpServer.close();  //stop accept new connection
}

void MainWindow::updateProgress()
{
  bytesReceived += (int)tcpServerSocket->bytesAvailable();
  tcpServerSocket->readAll();

  ui->progressBar->setMaximum(TotalBytes);
  ui->progressBar->setValue(bytesReceived);
  ui->labelState->setText(tr("Received %1MB")
                          .arg(bytesReceived / (1024 * 1024)));

  if (bytesReceived == TotalBytes) {
    tcpServerSocket->close();
    ui->btnStart->setEnabled(true);
  }
}

void MainWindow::handleSocketError(QAbstractSocket::SocketError socketError)
{
  if(QTcpSocket::RemoteHostClosedError == socketError)
    return;


}

void MainWindow::startTransfer()
{

}
