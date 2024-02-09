#ifndef TEMPSENSOR_H
#define TEMPSENSOR_H
#include<vector>
#include<string>

class TempSensor
{
private:
    double resistance;
    double temperature;

public:
    TempSensor(const double & = 0, const double & = 0);
    virtual ~TempSensor() = default;
    void setResistence(const double &);
    double getResistence() const;
    void setTemperature(const double &);
    virtual double getTemperature() const;
};

#endif // TEMPSENSOR  _H
