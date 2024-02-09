#ifndef ACCERELLOMETER_H
#define ACCERELLOMETER_H
#include "MovSens.h"
#include "Sensor.h"

class Accellerometer : public MovSens, public Sensor
{
private:
    double velocity;

public:
    Accellerometer(const std::string &, const std::string &, const std::string & = "",const std::vector<double>& ={}, const double & = 0, const double & = 0);
    ~Accellerometer() = default;
    double getVelocity() const;
    void setVelocity(const double&);
    void setName(const std::string &) override;
    void setModel(const std::string &) override;
    std::string getName() const override;
    std::string getModel() const override;
    void addMisuration (const std::function<double(double, double)>&) override;
    std::string getDescription() const override;
    void setDescription(const std::string &) override;
};
#endif // ACCERELLOMETER_H
