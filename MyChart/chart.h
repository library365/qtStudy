#ifndef CHART_H
#define CHART_H

class qreal;
class QLineSeries;
class QValueAxis;
class QTimer;

class Chart : public QChart
{
  Q_OBJECT

public:
  Chart(QGraphicsItem* parent=nullptr, Qt::WindowFlags wFlag = 0);
  virtual ~Chart();

public slots:
  void handleTimeout();

private:
  QLineSeries* line;
  QTimer* timer;
  QValueAxis* axis;
  qreal step;
  qreal x;
  qreal y;
};

#endif // CHART_H
