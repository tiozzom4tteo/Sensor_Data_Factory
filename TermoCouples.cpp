#include "TermoCouples.h"

TermoCouples::TermoCouples(const std::string &n, const std::string &m, const std::string &d,const std::vector<double>& mis, const double& r, const double& t) : TempSensor(r, t), Sensor(n,m,d,mis), cSeebeck(0), temperature(0) {};

void TermoCouples::setName(const std::string &nam)
{
    name = nam;
}

void TermoCouples::setModel(const std::string &mod)
{
    model = mod;
}

std::string TermoCouples::getName() const
{
    return name;
}

std::string TermoCouples::getModel() const
{
    return model;
}


void TermoCouples::addMisuration(const std::function<double (double, double)> &clamp)
{
    double deltaT = (temperature - TempSensor::getTemperature());
    double misuration = getResistence() * cSeebeck * deltaT;
    misurations.push_back(clamp(misuration,125));
}

void TermoCouples::setTemperature(const double &temp)
{
    temperature = temp;
}

double TermoCouples::getTemperature() const
{
    return temperature;
}

void TermoCouples::setSeebeck(const double &seeb)
{
    cSeebeck = seeb;
}

double TermoCouples::getSeebeck() const
{
    return cSeebeck;
}

std::string TermoCouples::getDescription() const
{
    return description;
}

void TermoCouples::setDescription(const std::string & d)
{
    description = d;
}
