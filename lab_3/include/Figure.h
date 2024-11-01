#ifndef LAB_3_FIGURE_H
#define LAB_3_FIGURE_H

#include <ostream>
#include <istream>
#include "Point.h"

class Figure
{
public:
    Figure() = default;
    Figure(point const* arr)
    {
        dots = new point[angles];
        std::memcpy(dots, arr, angles);
    }
    virtual double area() const = 0;
    virtual point center() const = 0;
    virtual operator double() = 0;
    virtual ~Figure() = 0;

    friend std::ostream& operator<<(std::ostream& os, Figure const& value);
    friend std::istream& operator>>(std::istream& is, Figure& value);

protected:
    point* dots;

};

std::ostream& operator<<(std::ostream& os, Figure const& value)
{
    return os;
}

std::istream& operator>>(std::istream& is, Figure& value)
{
    return is;
}

#endif //LAB_3_FIGURE_H
