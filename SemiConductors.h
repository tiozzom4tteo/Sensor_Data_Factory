#ifndef SEMICONDUCTORS_H
#define SEMICONDUCTORS_H
#include "GasSensor.h"
#include "Sensor.h"
#include <cmath>

class SemiConductors : public GasSensor, public Sensor
{
private:
    double density;
    int coeffCalibr;

public:
    SemiConductors(const std::string &, const std::string &, const std::string & = "", const std::vector<double> & = {}, const double & = 0, const bool & = false); // nome, modello, resistenza, densita, misura
    ~SemiConductors() = default;
    double getDensity() const;
    void setDensity(const double &);
    void setName(const std::string &) override;
    void setModel(const std::string &) override;
    std::string getName() const override;
    std::string getModel() const override;
    void addMisuration(const std::function<double(double, double)> &) override;
    int getCoeffCalibr() const;
    void setCoeffCalibr(const double &);
    std::string getDescription() const override;
    void setDescription(const std::string &) override;
};

#endif // SemiConductors_H
