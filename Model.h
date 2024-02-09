#ifndef MODEL_H
#define MODEL_H
#include "CreatorSensors.h"
#include "SensorsDashboard.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <iterator>
#include <algorithm>

class Model
{
private:
    SensorsDashboard *dashboard;

public:
    Model();
    ~Model();
    void addElettroSensor(const std::string &, const std::string &, const std::string &, const std::vector<double>& ={}) const;
    void addNewGiroscopeSensor(const std::string &, const std::string &, const std::string &, const std::vector<double>& ={}) const;
    void addNewAccelerometerSensor(const std::string &, const std::string &, const std::string &, const std::vector<double>& ={}) const;
    void addTermoResistance(const std::string &, const std::string &, const std::string &, const std::vector<double>& ={}) const;
    void addNewTermoCouplesSensor(const std::string &, const std::string &, const std::string &, const std::vector<double>& ={}) const;
    void addNewSemiSensor(const std::string &, const std::string &, const std::string &, const std::vector<double>& ={}) const;
    void removeSensor(unsigned int index);
    void nextSensor(const unsigned int&) const;
    void previousSensor(const unsigned int&) const;
    void nextSensorTyped(const unsigned int&) const;
    void previousSensorTyped(const unsigned int&) const;
    void modifySensor(const unsigned int&, const std::string &, const std::string &, const std::string &);
    Sensor *getSensor(unsigned int index) const;
    unsigned int getCurrentSensor() const;
    unsigned int getSensorsSize() const;
    std::vector<Sensor *> getGasSensors() const;
    std::vector<Sensor *> getMovmentSensors() const;
    std::vector<Sensor *> getTemperatureSensors() const;
    std::vector<Sensor *> getSensors() const;
    void load(const std::string &);
    void save(const std::string &);
};

#endif // MODEL_H
