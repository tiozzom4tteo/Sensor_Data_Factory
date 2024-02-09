#ifndef ELETTROSENSOR_H
#define ELETTROSENSOR_H
#include "GasSensor.h"
#include "Sensor.h"

class ElettroSensor : public GasSensor, public Sensor
{
private:
    static double cFaraday;
    static float costCinetica;
    float concElem;
    double intensity_num_elettr;
    double voltage;

public:
    ElettroSensor(const std::string &, const std::string &, const std::string & = "",const std::vector<double>& ={}, const double & = 0, const bool & = false);
    ~ElettroSensor() = default;
    double getIntensity() const;
    double getVoltage() const;
    void setConcElem(const float &);
    float getConcElem() const;
    void setIntensity(const double &);
    void setName(const std::string &) override;
    void setModel(const std::string &) override;
    void setVoltage(const double &);
    std::string getName() const override;
    std::string getModel() const override;
    void addMisuration (const std::function<double(double, double)>&) override;
    std::string getDescription() const override;
    void setDescription(const std::string &) override;
};

#endif // ELETTROSENSOR_H
