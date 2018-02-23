#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QOpenGLWindow>
#include <QOpenGLFunctions>

namespace Ui {
  class MainWindow;
}

class MainWindow : public QOpenGLWindow, protected QOpenGLFunctions
{
  Q_OBJECT

public:
  explicit MainWindow();
  ~MainWindow();

  void initializeGL();
  void resizeGL(int, int);
  void paintGL();
  void teardownGL();

private:
  void printContextInformation();
};

#endif // MAINWINDOW_H
