#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
  class MainWindow;
}

class QTcpSocket;

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

private slots:
  void parseMsg();

  void doConnect();
  void cutConnection();

  void socketWrite();

private:
  Ui::MainWindow *ui;

  QTcpSocket* socket;
};

#endif // MAINWINDOW_H
