#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtDebug>

#include <QtCharts/QChartView>

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  line = new QLineSeries(this);
  spline = new QSplineSeries(this);

  line->append(0, 6);
  line->append(2, 4);
  line->append(3, 8);
  line->append(7, 4);
  line->append(10, 5);
  line->append(11, 1);
  line->append(13, 3);
  line->append(17, 6);
  line->append(18, 3);
  line->append(20, 2);

  spline->append(0, 3);
  spline->append(2, 8);
  spline->append(3, 2);
  spline->append(7, 7);
  spline->append(10, 1);
  spline->append(11, 9);
  spline->append(13, 4);
  spline->append(17, 7);
  spline->append(18, 5);
  spline->append(20, 8);

  chart = new QChart();
  chart->legend()->hide();
  chart->addSeries(line);
  chart->addSeries(spline);
  chart->setAnimationOptions(QChart::AllAnimations);
  chart->setAnimationDuration(10);
  chart->createDefaultAxes();

  chartView = new QChartView(chart, this);
  chartView->setRenderHint(QPainter::Antialiasing);

  setCentralWidget(chartView);
}

MainWindow::~MainWindow()
{
  delete ui;
}
