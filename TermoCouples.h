#ifndef TERMOCOUPLES_H
#define TERMOCOUPLES_H
#include "TempSensor.h"
#include "Sensor.h"

class TermoCouples : public TempSensor, public Sensor
{
private:
    double cSeebeck;
    double temperature;

public:
    TermoCouples(const std::string &, const std::string &, const std::string & = "",const std::vector<double>& ={}, const double & = 0, const double & = 0);
    ~TermoCouples() = default;
    void setTemperature(const double &);
    double getTemperature() const override;
    void setSeebeck(const double &);
    double getSeebeck() const;
    void setName(const std::string &) override;
    void setModel(const std::string &) override;
    std::string getName() const override;
    std::string getModel() const override;
    void addMisuration (const std::function<double(double, double)>&) override;
    std::string getDescription() const override;
    void setDescription(const std::string &) override;
};

#endif // TERMOCOUPLES_H
