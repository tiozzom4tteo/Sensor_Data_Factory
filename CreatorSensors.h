#ifndef CREATORSENSORS_H
#define CREATORSENSORS_H
#include "SemiConductors.h"
#include "Accellerometer.h"
#include "ElettroSensor.h"
#include "Giroscope.h"
#include "TermoResistance.h"
#include "TermoCouples.h"
#include <vector>
#include <stdexcept>

class CreatorSensors
{
public:
    SemiConductors *createSemiSensor(const std::string &, const std::string &, const std::string & = "", const std::vector<double> & = {}, const double & = 0, const bool & = false) const;
    Accellerometer *createAccellSensor(const std::string &, const std::string &, const std::string & = "", const std::vector<double> & = {}, const double & = 0, const double & = 0) const;
    ElettroSensor *createElettroSensor(const std::string &, const std::string &, const std::string & = "", const std::vector<double> & = {}, const double & = 0, const bool & = false) const;
    Giroscope *createGiroscopeSensor(const std::string &, const std::string &, const std::string & = "", const std::vector<double> & = {}, const double & = 0, const double & = 0) const;
    TermoResistance *createTermoresistanceSensor(const std::string &, const std::string &, const std::string & = "", const std::vector<double> & = {}, const double & = 0, const double & = 0) const;
    TermoCouples *createTermocouplesSensor(const std::string &, const std::string &, const std::string & = "", const std::vector<double> & = {}, const double & = 0, const double & = 0) const;
    void validate(const std::string &, const std::string &) const;
};

#endif // CREATORESENSORI_H
