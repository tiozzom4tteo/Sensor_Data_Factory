#include "Sensor.h"

Sensor::Sensor(const std::string &n, const std::string &m, const std::string &d, const std::vector<double> &mis) : name(n), model(m), description(d), misurations(mis){};

bool Sensor::operator==(const Sensor &s1) const
{
    return (name == s1.getName());
}

void Sensor::clear()
{
    misurations = {};
}

std::vector<double> Sensor::getMisurations() const
{
    return misurations;
}

double Sensor::getLastMisurations() const
{
    if ((int)misurations.size() > 0)
        return misurations[misurations.size() - 1];
    else
        return 0;
}
