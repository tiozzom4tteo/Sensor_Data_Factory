#ifndef GIROSCOPE_H
#define GIROSCOPE_H
#include "MovSens.h"
#include "Sensor.h"

class Giroscope : public MovSens, public Sensor
{
private:
    double second_pos;
    int tempo1, tempo2;

public:
    Giroscope(const std::string &, const std::string &, const std::string & = "",const std::vector<double>& ={}, const double & = 0, const double & = 0);
    ~Giroscope() = default;
    double getSecPos() const;
    void setSecPos(double);
    void setTempo1(int);
    void setTempo2(int);
    int getTempo1() const;
    int getTempo2() const;
    void setName(const std::string &) override;
    void setModel(const std::string &) override;
    std::string getName() const override;
    std::string getModel() const override;
    void addMisuration (const std::function<double(double, double)>&) override;
    std::string getDescription() const override;
    void setDescription(const std::string &) override;
};
#endif // GIROSCOPE_H
