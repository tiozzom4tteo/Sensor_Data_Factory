#include "MovSens.h"

MovSens::MovSens(const double &pos1, const double &pos2) : position1(pos1), position2(pos2){};

void MovSens::setPosition1(const double &pos)
{
    position1 = pos;
}

double MovSens::getPosition1() const
{
    return position1;
}

double MovSens::getPosition2() const
{
    return position2;
}

void MovSens::setPosition2(const double &pos)
{
    position2 = pos;
}

void MovSens::setVariation(const double &val)
{
    variation = val;
}
double MovSens::getVariation() const
{
    return variation;
}
