#include "CreatorSensors.h"

void CreatorSensors::validate(const std::string &name, const std::string &model) const
{
    if (name == "" || model == "")
    {
        throw std::runtime_error("Error: name or model fields are empty");
    }
}

SemiConductors *CreatorSensors::createSemiSensor(const std::string &name, const std::string &model, const std::string &description, const std::vector<double> &misurations, const double &r, const bool &p) const
{
    validate(name, model);
    return new SemiConductors(name, model, description, misurations, r, p);
}

Accellerometer *CreatorSensors::createAccellSensor(const std::string &name, const std::string &model, const std::string &description, const std::vector<double> &misurations, const double &p, const double &v) const
{
    validate(name, model);
    return new Accellerometer(name, model, description, misurations, p, v);
}

ElettroSensor *CreatorSensors::createElettroSensor(const std::string &name, const std::string &model, const std::string &description, const std::vector<double> &misurations, const double &r, const bool &p) const
{
    validate(name, model);
    return new ElettroSensor(name, model, description, misurations, r, p);
}

Giroscope *CreatorSensors::createGiroscopeSensor(const std::string &name, const std::string &model, const std::string &description, const std::vector<double> &misurations, const double &p, const double &v) const
{
    validate(name, model);
    return new Giroscope(name, model, description, misurations, p, v);
}

TermoResistance *CreatorSensors::createTermoresistanceSensor(const std::string &name, const std::string &model, const std::string &description, const std::vector<double> &misurations, const double &r, const double &t) const
{
    validate(name, model);
    return new TermoResistance(name, model, description, misurations, r, t);
}

TermoCouples *CreatorSensors::createTermocouplesSensor(const std::string &name, const std::string &model, const std::string &description, const std::vector<double> &misurations, const double &r, const double &t) const
{
    validate(name, model);
    return new TermoCouples(name, model, description, misurations, r, t);
}
