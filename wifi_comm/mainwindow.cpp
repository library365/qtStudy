#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>

#include "QTcpSocket"



MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  socket = new QTcpSocket(this);

  QMessageBox::StandardButton ret;

  do{
    ret = QMessageBox::critical(this
                              , "title"
                              , "text"
                              , QMessageBox::Retry | QMessageBox::Cancel);
//  if(QMessageBox::Cancel == ret)
//    return;

  }while(QMessageBox::Retry == ret);

}

MainWindow::~MainWindow()
{
  delete ui;
}


void MainWindow::parseMsg()
{
  QByteArray byte = socket->readAll();
  qDebug(byte);
  //handle msg at mavlink
  //...
}

void MainWindow::doConnect()
{
//  socket->connectToHost(ui->leditIp->text(), ui->leditPort->text.toInt());
//  if(socket->waitForConnected(1000))
//  {
//    qDebug("connected.");
//  }
//  else{
//    qDebug("Connect fail");
//  }
}

void MainWindow::cutConnection()
{
  socket->close();
}

void MainWindow::socketWrite()
{
  socket->write("message from app");
}
