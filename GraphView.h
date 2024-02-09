#ifndef GRAPHVIEW_H
#define GRAPHVIEW_H

#include <QFrame>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QtCharts>
#include <cstdlib>
#include <ctime>
#include <random>
#include "Sensor.h"
#include "SemiConductors.h"
#include "ElettroSensor.h"
#include "TermoResistance.h"
#include "TermoCouples.h"
#include "Accellerometer.h"
#include "Giroscope.h"

class SensorsViewerManager;

class GraphView : public QWidget
{
    Q_OBJECT

private:
    SensorsViewerManager *manager;
    Sensor *sensor;
    QLineSeries *series;
    QChart *chart;
    QValueAxis *axisX;
    QValueAxis *axisY;
    QLabel *name;
    QLabel *model;
    qreal currentXValue;
    unsigned int currentIndex;
    std::string type;
    int maxX;
    int maxY;
    int minY;

public:
    explicit GraphView(QWidget *parent = nullptr);
    ~GraphView();
    void setManager(SensorsViewerManager *);
    QFrame *addGraphView();
    void setCurrentSensor(Sensor *);
    void nextSens(Sensor *);
    void prevSens(Sensor *);
    void setCurrentIndex(const unsigned int &);
    unsigned int getCurrentIndex() const;
    void setCurrentType(const std::string &);
    std::string getCurrentType() const;
    Sensor *getCurrentSensor() const;
    void setGraph();

signals:
};

#endif // GRAPHVIEW_H
