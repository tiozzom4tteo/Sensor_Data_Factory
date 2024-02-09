#ifndef MOVSENS_H
#define MOVSENS_H
#include <vector>
#include <string>

class MovSens
{
private:
    double position1;
    double position2;
    double variation;

public:
    MovSens(const double & = 0, const double & = 0);
    virtual ~MovSens() = default;
    void setPosition1(const double &);
    double getPosition1() const;
    void setPosition2(const double &);
    double getPosition2() const;
    double getVariation() const;
    void setVariation(const double &);
};

#endif // MOVSENS_H
