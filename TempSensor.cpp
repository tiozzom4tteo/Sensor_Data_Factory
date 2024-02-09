#include "TempSensor.h"

TempSensor::TempSensor(const double &res, const double &mis) : resistance(res), temperature(mis){};

void TempSensor::setResistence(const double &res)
{
    resistance = res;
}

double TempSensor::getResistence() const
{
    return resistance;
}

void TempSensor::setTemperature(const double &temp)
{
    temperature = temp;
}

double TempSensor::getTemperature() const
{
    return temperature;
}
