#ifndef SENSORSVIEWERMANAGER_H
#define SENSORSVIEWERMANAGER_H

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
#include <QWidget>
#include <QPlainTextEdit>
#include <QTextBrowser>
#include <QTextEdit>
#include <QApplication>
#include <QTimer>
#include <vector>
#include <QShortcut>
#include "Sensor.h"
#include "SensorsViewer.h"
#include "SensorView.h"
#include "CreateView.h"
#include "ModifyView.h"
#include "GraphView.h"
#include "CreatorSensors.h"

class Controller;
class Sensor;
class SensorsViewerManager : public QWidget
{
    Q_OBJECT
private:
    SensorsViewer *home;
    SensorView *sensorView;
    CreateView *createView;
    ModifyView *modifyView;
    GraphView *graphview;
    Controller *controller;
    QFrame *window;
    QStackedLayout *mainLayout;
    QMenuBar *menubar;
    QMenu *file;
    QMenu *create;
    QMenu *menu;
    QTimer *timer;
    QValueAxis *axisX;
    QValueAxis *axisY;

public:
    explicit SensorsViewerManager(QWidget *parent = nullptr);
    ~SensorsViewerManager();
    void setController(Controller *);
    void show() const;
    void addMenu();
    SensorsViewer *getHomeView() const;
    SensorView *getSensorView() const;
    CreateView *getCreateView() const;
    ModifyView *getModifyView() const;
    GraphView* getGraphView() const;
    void showSensorsView(const std::vector<Sensor *> &);
    void showModifySensorView(const std::string &, const std::string &, const std::string &);
    void showGraphSensorView(Sensor *, const unsigned int&, const std::string&) const;
    void deleteSensor(QFrame *, const unsigned int&) const;
    void modifySensor(const std::string &, const std::string &, const std::string &) const;
    void createSensor(const unsigned int&, const std::string&, const std::string&, const std::string&) const;

public slots:
    void showHome() const;
    void closeApplication() const;
    void showCreateSensorsView() const;
    void StartTimer() const;
    void StopTimer() const;
    void NextSensor() const;
    void PreviousSensor() const;
    

signals:
};

#endif // SENSORSVIEWERMANAGER_H
