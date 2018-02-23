#include "chart.h"

#include <QtCharts>
#include <QtCore>

Chart::Chart(QGraphicsItem* parent, Qt::WindowFlags wFlags)
  : QChart(QChart::ChartTypeCartesian, parent, wFlags)
  , line(nullptr)
{
  connect(timer, SIGNAL(timeout()), SLOT(handleTimeout()));
  timer = new QTimer(this);
  timer->setInterval(500);

  line = new QLineSeries(this);
  QPen red



}

void Chart::handleTimeout()
{

}
