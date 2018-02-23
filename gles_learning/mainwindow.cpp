#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow()
{
}

MainWindow::~MainWindow()
{
  makeCurrent();
  teardownGL();
}

void MainWindow::initializeGL()
{
  qDebug("initializeGL.");
  initializeOpenGLFunctions();
  printContextInformation();

  glClearColor(0, 0, 1, 1);
}

void MainWindow::resizeGL(int _w, int _h)
{
  qDebug("resizeGL.");
  _w, _h;
}

void MainWindow::paintGL()
{
  qDebug("paintGL.");
  glClear(GL_COLOR_BUFFER_BIT);

  translate
  glRotatef(1,1,1,1);
  glBegin(GL_LINES);
  glEnd();
}

void MainWindow::teardownGL()
{

}

void MainWindow::printContextInformation()
{
  QString glType = context()->isOpenGLES() ? "OpenGL_ES" : "OpenGL";
  const char* s = reinterpret_cast<const char*>(glGetString(GL_VERSION));
  QString glVersion(s);
  QString glProfile;

#define CASE(c) case QSurfaceFormat::c: glProfile = #c; break
  switch (format().profile())
  {
    CASE(NoProfile);
    CASE(CoreProfile);
    CASE(CompatibilityProfile);
  }
#undef CASE

  qDebug() << qPrintable(glType) << qPrintable(glVersion) << "(" << qPrintable(glProfile) << ")";
}
