#ifndef GASSENSOR_H
#define GASSENSOR_H
#include<vector>
#include<string>

class GasSensor
{
protected:
    double resistence;
    bool presence;

public:
    GasSensor(const double & = 0, const bool & = false);
    virtual ~GasSensor() = default;
    void setPresence(const bool &);
    bool getPresence() const;
    void setResistence(const double &);
    double getResistence() const;
};

#endif // SENSOREGAS_H
