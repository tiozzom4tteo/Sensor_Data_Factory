#ifndef TERMORESISTANCE_H
#define TERMORESISTANCE_H
#include "TempSensor.h"
#include "Sensor.h"

class TermoResistance : public TempSensor, public Sensor
{
private:
    double temperature;

public:
    TermoResistance(const std::string &, const std::string &, const std::string & = "",const std::vector<double>& ={}, const double & = 0, const double & = 0);
    ~TermoResistance() = default;
    void setName(const std::string &) override;
    void setModel(const std::string &) override;
    std::string getName() const override;
    std::string getModel() const override;
    void addMisuration (const std::function<double(double, double)>&) override;
    void setTemperature(const double &);
    double getTemperature() const override;
    std::string getDescription() const override;
    void setDescription(const std::string &) override;
};

#endif
