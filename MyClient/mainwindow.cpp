#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtNetwork>

#include <QTcpSocket>
#include <QDataStream>
#include <QNetworkSession>

static const int TotalBytes = 50 * 1024 * 1024;
static const int PayloadSize = 64 * 1024; // 64 KB

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
  , socket(new QTcpSocket(this))
  , session(Q_NULLPTR)
{
  ui->setupUi(this);
  //hostCombo->setEditable(true) set in .ui

  //find out this device's name
//  QString name = QHostInfo::localHostName();
//  if(!name.isEmpty()){
//    ui->comboHost->addItem(name);
//    QString domain = QHostInfo::localDomainName();
//    if (!domain.isEmpty())
//      ui->comboHost->addItem(name + QChar('.') + domain);
//  }
//  if (name != QLatin1String("localhost"))
//      ui->comboHost->addItem(QString("localhost"));
//  // find out IP addresses of this machine
//  QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
//  // add non-localhost addresses
//  for (int i = 0; i < ipAddressesList.size(); ++i) {
//      if (!ipAddressesList.at(i).isLoopback())
//          ui->comboHost->addItem(ipAddressesList.at(i).toString());
//  }
//  // add localhost addresses
//  for (int i = 0; i < ipAddressesList.size(); ++i) {
//      if (ipAddressesList.at(i).isLoopback())
//          ui->comboHost->addItem(ipAddressesList.at(i).toString());
//  }

//  ui->leditPort->setValidator(new QIntValidator(1, 65535, this));

//  in->setDevice(socket);
  //in->setVersion(...);

//  connect(socket, &QIODevice::readyRead, this, &MainWindow::readMsg);
//  connect(socket, QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error)
//          , this, &MainWindow::dpError);




//  QNetworkConfigurationManager manager;
  connect(ui->btnConnect, SIGNAL(released()), SLOT(start()));
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::start()
{
  ui->btnStart->setEnabled(false);


  //byteWritten = 0;

  socket->connectToHost(ui->comboServerName->currentText(), ui->leditServerPort->text().toInt());

  connect(socket, SIGNAL(connected()), SLOT(startTransfer()));
//  connect(socket, SIGNAL(connected()), SLOT(startTransfer()));
}

void MainWindow::startTransfer()
{
  //called when client connected to the server
  connect(socket, SIGNAL(bytesWritten(qint64))
          , SLOT(updateClientProgress(qint64)));

  bytesToWrite = TotalBytes - (int)socket->write(QByteArray(PayloadSize, '@'));
  ui->labelSocketState->setText(tr("Connected"));

}

void MainWindow::updateClientProgress(qint64 nBytes)
{
  // callen when the TCP client has written some bytes
  bytesWritten += (int)nBytes;

  // only write more if not finished and when the Qt write buffer is below a certain size.
  if (bytesToWrite > 0 && socket->bytesToWrite() <= 4*PayloadSize)
      bytesToWrite -= socket->write(QByteArray(qMin(bytesToWrite, PayloadSize), '@'));

  ui->progressBar->setMaximum(TotalBytes);
  ui->progressBar->setValue(bytesWritten);
  ui->labelSocketState->setText(tr("Sent %1MB").arg(bytesWritten / (1024 * 1024)));
}

void MainWindow::rqMsg()
{
  socket->connectToHost(ui->comboServerName->currentText(), ui->leditServerPort->text().toInt());
}

void MainWindow::readMsg()
{

}


void MainWindow::dpError(QAbstractSocket::SocketError socketError)
{

}

void MainWindow::sessionOpened()
{

}
