#include "SemiConductors.h"

SemiConductors::SemiConductors(const std::string &n, const std::string &m, const std::string &d, const std::vector<double> &mis, const double &r, const bool &p) : GasSensor(r, p), Sensor(n, m, d, mis), density(0), coeffCalibr(0){};

double SemiConductors::getDensity() const
{
    return density;
}

void SemiConductors::setDensity(const double &den)
{
    density = den;
}

void SemiConductors::setName(const std::string &nam)
{
    name = nam;
}

void SemiConductors::setModel(const std::string &mod)
{
    model = mod;
}

std::string SemiConductors::getName() const
{
    return name;
}

std::string SemiConductors::getModel() const
{
    return model;
}

void SemiConductors::addMisuration(const std::function<double(double, double)> &clamp)
{
    double misuration = density * coeffCalibr * std::pow(M_E, getResistence());
    misurations.push_back(clamp(misuration, 3711));
}

int SemiConductors::getCoeffCalibr() const
{
    return coeffCalibr;
}

void SemiConductors::setCoeffCalibr(const double &coeff)
{
    coeffCalibr = coeff;
}

std::string SemiConductors::getDescription() const
{
    return description;
}

void SemiConductors::setDescription(const std::string &d)
{
    description = d;
}
