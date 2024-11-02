#ifndef LAB_3_FIGURE_H
#define LAB_3_FIGURE_H

#include <string>
#include <cmath>
#include "point.h"

class Figure
{
public:
    Figure() = default;
    virtual double square() const = 0;
    virtual Point center() const = 0;
    virtual operator double() const = 0;
    ~Figure() = default;
};

#endif