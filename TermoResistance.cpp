#include "TermoResistance.h"

TermoResistance::TermoResistance(const std::string &n, const std::string &m, const std::string &d,const std::vector<double>& mis, const double& r, const double& t) : TempSensor(r, t), Sensor(n,m,d,mis), temperature(0) {};

void TermoResistance::setName(const std::string &nam)
{
    name = nam;
}

void TermoResistance::setModel(const std::string &mod)
{
    model = mod;
}

std::string TermoResistance::getName() const
{
    return name;
}

std::string TermoResistance::getModel() const
{
    return model;
}

void TermoResistance::addMisuration(const std::function<double (double, double)> & clamp)
{
    double misuration = getResistence() * (1 + (0.00385 * (temperature-getTemperature())));
    misurations.push_back(clamp(misuration, 6));
}

void TermoResistance::setTemperature(const double &temp)
{
    temperature = temp;
}

double TermoResistance::getTemperature() const
{
    return temperature;
}

std::string TermoResistance::getDescription() const
{
    return description;
}

void TermoResistance::setDescription(const std::string & d)
{
    description = d;
}
