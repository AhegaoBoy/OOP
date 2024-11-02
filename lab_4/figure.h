#ifndef LAB_4_FIGURE_H
#define LAB_4_FIGURE_H


#include <iostream>
#include <string>
#include <cmath>
#include "point.h"

template <typename T>
class Figure{
public:
    Figure() = default;

    virtual T square() const = 0;
    virtual Point<T> center() const = 0;
    virtual operator double() const = 0;

    ~Figure() = default;
};

#endif
