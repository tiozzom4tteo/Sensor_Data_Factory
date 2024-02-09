#include "Giroscope.h"

Giroscope::Giroscope(const std::string &n, const std::string &m, const std::string &d,const std::vector<double>& mis, const double& p, const double& v) : MovSens(p, v), Sensor(n,m,d,mis), second_pos(0), tempo1(0), tempo2(0) {};

double Giroscope::getSecPos() const
{
    return second_pos;
}

void Giroscope::setSecPos(double pos)
{
    second_pos = pos;
}

void Giroscope::setTempo1(int temp)
{
    tempo1 = temp;
}

void Giroscope::setTempo2(int temp)
{
    tempo2 = temp;
}

int Giroscope::getTempo1() const
{
    return tempo1;
}

int Giroscope::getTempo2() const
{
    return tempo2;
}

void Giroscope::setName(const std::string &nam)
{
    name = nam;
}

void Giroscope::setModel(const std::string &mod)
{
    model = mod;
}

std::string Giroscope::getName() const
{
    return name;
}

std::string Giroscope::getModel() const
{
    return model;
}

void Giroscope::addMisuration(const std::function<double (double, double)> &clamp)
{
    float deltaTempo = (tempo2 - tempo1);
    float variazione_angolo = (second_pos - getPosition2());
    float omega = variazione_angolo / deltaTempo;
    double misuration = omega * deltaTempo;// *3
    misurations.push_back(clamp(misuration, 25));
}

std::string Giroscope::getDescription() const
{
    return description;
}

void Giroscope::setDescription(const std::string & d)
{
    description = d;
}
