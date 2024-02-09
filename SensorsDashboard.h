#ifndef SENSORSDASHBOARD_H
#define SENSORSDASHBOARD_H
#include "GasSensor.h"
#include "TempSensor.h"
#include "MovSens.h"
#include "Sensor.h"
#include <vector>
#include <iostream>

class SensorsDashboard
{
private:
    int currentSensor;
    std::vector<Sensor *> sensors;

public:
    SensorsDashboard();
    ~SensorsDashboard();
    void addSensor(Sensor *sensor);
    void removeSensor(unsigned int index);
    unsigned int getCurrentSensor() const;
    Sensor *getSensor(unsigned int index) const;
    unsigned int getSize() const;
    void previous();
    void next();
    void previousTyped(const unsigned int &);
    void nextTyped(const unsigned int &);
    void goToStart();
    void goToEnd();
    void modifySensor(const unsigned int &, const std::string &, const std::string &, const std::string &);
    void setCurrentIndex(const unsigned int &);
    std::vector<Sensor *> getSensorsOfGasType() const;
    std::vector<Sensor *> getSensorsOfMovmentType() const;
    std::vector<Sensor *> getSensorsOfTemperatureType() const;
    std::vector<Sensor *> getSensors() const;
};

#endif // DASHBOARDSENSORI_H
