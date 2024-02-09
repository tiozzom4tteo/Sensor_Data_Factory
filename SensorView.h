#ifndef SENSORVIEW_H
#define SENSORVIEW_H

#include <QWidget>
#include <QFrame>
#include <QMenu>
#include <QMenuBar>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QAction>
#include <QStackedLayout>
#include <QScrollArea>
#include "Sensor.h"
#include "TempSensor.h"
#include "GasSensor.h"
#include "MovSens.h"

class SensorsViewerManager;

class SensorView : public QWidget
{
    Q_OBJECT

private:
    SensorsViewerManager *manager;
    QFrame *mainContainer;
    QLineEdit *findInput;
    QScrollArea *scrollArea;
    QWidget *scrollContent;
    QVBoxLayout *scrollLayout;
    std::string view;

public:
    explicit SensorView(QWidget *parent = nullptr);
    ~SensorView();
    QFrame *addSensorsView();
    void cleanScrollView();
    void addSensorToView(const std::vector<Sensor *> &);
    void setManager(SensorsViewerManager *);
    void setView(const std::string &);
    void createSensorPerView(Sensor *, const std::string &, const QPixmap &, const unsigned int &);

public slots:
    void findSensors() const;

signals:
};

#endif // SENSORVIEW_H
