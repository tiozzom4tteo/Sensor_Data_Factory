#include "Accellerometer.h"

Accellerometer::Accellerometer(const std::string &n, const std::string &m, const std::string &d,const std::vector<double>& mis, const double& p, const double& v) : MovSens(p, v), Sensor(n,m,d,mis),
    velocity(0){}

double Accellerometer::getVelocity() const
{
    return velocity;
}

void Accellerometer::setVelocity(const double& vel)
{
    velocity = vel;
}

void Accellerometer::setName(const std::string &nam)
{
    name = nam;
}

void Accellerometer::setModel(const std::string &mod)
{
    model = mod;
}

std::string Accellerometer::getName() const
{
    return name;
}

std::string Accellerometer::getModel() const
{
    return model;
}

void Accellerometer::addMisuration(const std::function<double (double, double)> &clamp)
{
    double misuration = std::abs(velocity - ((getPosition2() - getPosition1())/getVariation())) / getVariation();
    misurations.push_back(clamp(misuration, 5));
}

std::string Accellerometer::getDescription() const
{
    return description;
}

void Accellerometer::setDescription(const std::string &d)
{
    description = d;
}
