#include "ElettroSensor.h"

ElettroSensor::ElettroSensor(const std::string &n, const std::string &m, const std::string &d,const std::vector<double>& mis, const double& r, const bool& p) : GasSensor(r, p), Sensor(n,m,d,mis), concElem(0), intensity_num_elettr(0), voltage(0) {};

double ElettroSensor::getIntensity() const
{
    return intensity_num_elettr;
}

double ElettroSensor::getVoltage() const
{
    return voltage;
}

void ElettroSensor::setIntensity(const double &i)
{
    intensity_num_elettr = i;
}

void ElettroSensor::setConcElem(const float &conc)
{
    concElem = conc;
}

float ElettroSensor::getConcElem() const
{
    return concElem;
}

void ElettroSensor::setName(const std::string &nam)
{
    name = nam;
}

void ElettroSensor::setModel(const std::string &mod)
{
    model = mod;
}

void ElettroSensor::setVoltage(const double &volt)
{
    voltage = volt;
}

std::string ElettroSensor::getName() const
{
    return name;
}

std::string ElettroSensor::getModel() const
{
    return model;
}

double ElettroSensor::cFaraday = 96.485;
float ElettroSensor::costCinetica = 0.5;

void ElettroSensor::addMisuration(const std::function<double(double, double)>& clamp)
{
    double misuration = intensity_num_elettr * cFaraday * costCinetica * concElem;
    misurations.push_back(clamp(misuration, 1207));
}

std::string ElettroSensor::getDescription() const
{
    return description;
}

void ElettroSensor::setDescription(const std::string & d)
{
    description = d;
}
