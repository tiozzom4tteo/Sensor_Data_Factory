#include "GasSensor.h"

GasSensor::GasSensor(const double& res, const bool& pres) :resistence(res), presence(pres) {}

void GasSensor::setPresence(const bool &p)
{
    presence = p;
}
bool GasSensor::getPresence() const
{
    return presence;
}

void GasSensor::setResistence(const double &re)
{
    resistence = re;
}

double GasSensor::getResistence() const
{
    return resistence;
}
