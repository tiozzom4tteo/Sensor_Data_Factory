#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Model.h"
#include "SensorsViewerManager.h"
#include "SensorView.h"
#include <QApplication>
#include <QWidget>
#include <vector>
#include <QCoreApplication>
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

class Controller : public QWidget
{
    Q_OBJECT
private:
    SensorsViewerManager *viewer;
    Model *model;

public:
    explicit Controller(QWidget *parent = nullptr);
    ~Controller();
    void setModel(Model *);
    void setViewer(SensorsViewerManager *);
    void getSensors(const std::string &) const;
    void createSensors(const unsigned int &, const std::string &, const std::string &, const std::string &) const;
    void removeSensor(const unsigned int &);
    void modifySensor(const std::string &, const std::string &, const std::string &);
    void load(const unsigned int &);
    void next() const;
    void previous() const;

public slots:
    void save();
};

#endif // CONTROLLER_H
