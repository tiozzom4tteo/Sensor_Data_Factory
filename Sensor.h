#ifndef SENSOR_H
#define SENSOR_H
#include <string>
#include <iostream>
#include <vector>
#include <functional>

class Sensor
{
protected:
    std::string name;
    std::string model;
    std::string description;
    std::vector<double> misurations;

public:
    Sensor(const std::string &, const std::string &, const std::string & = "", const std::vector<double> & = {});
    virtual ~Sensor() = default;
    virtual void setName(const std::string &){};
    virtual void setModel(const std::string &){};
    virtual std::string getName() const = 0;
    virtual std::string getModel() const = 0;
    virtual std::string getDescription() const = 0;
    virtual void setDescription(const std::string &){};
    std::vector<double> getMisurations() const;
    double getLastMisurations() const;
    virtual void addMisuration(const std::function<double(double, double)> &){};
    bool operator==(const Sensor &) const;
    void clear();
};

#endif // SENSORE_H
