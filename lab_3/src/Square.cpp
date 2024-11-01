#include "Square.h"
#include "Point.h"

square::square(point arr[angles]) : Figure(arr)
{

}

square::square(const square &other) noexcept
{
    dots = new point[angles];
    std::memcpy(dots, other.dots, angles);
}

square &square::operator=(const square &other) noexcept
{
    if(this != &other)
    {
        dots = new point[angles];
        std::memcpy(dots, other.dots, angles);
    }
    return *this;
}

square::square(square &&other) noexcept
{
    dots = other.dots;
    other.dots = nullptr;
}

square& square::operator=(square &&other) noexcept
{
    if(this != &other)
    {
        dots = other.dots;
        other.dots = nullptr;
    }
    return *this;
}

double square::area() const
{
    return point::metrics(dots[0], dots[1]) * point::metrics(dots[1], dots[2]);
}

point square::center() const
{
    double x1 = dots[0].get_x();
    double x2 = dots[1].get_x();
    double y2 = dots[2].get_y();
    double y3 = dots[2].get_y();

    return point((x2 - x1) / 2.0, (y3 - y2) / 2.0);
}

