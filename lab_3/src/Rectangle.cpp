#include <Rectangle.h>
#include "Point.h"

rectangle::rectangle(point arr[angles]) : Figure(arr)
{

}

rectangle::rectangle(const rectangle &other) noexcept
{
    dots = new point[angles];
    std::memcpy(dots, other.dots, angles);
}

rectangle &rectangle::operator=(const rectangle &other) noexcept
{
    if(this != &other)
    {
        dots = new point[angles];
        std::memcpy(dots, other.dots, angles);
    }
    return *this;
}

rectangle::rectangle(rectangle &&other) noexcept
{
    dots = other.dots;
    other.dots = nullptr;
}

rectangle& rectangle::operator=(rectangle &&other) noexcept
{
    if(this != &other)
    {
        dots = other.dots;
        other.dots = nullptr;
    }
    return *this;
}

double rectangle::area() const
{
    return point::metrics(dots[0], dots[1]) * point::metrics(dots[1], dots[2]);
}

point rectangle::center() const
{
    double x1 = dots[0].get_x();
    double x2 = dots[1].get_x();
    double y2 = dots[2].get_y();
    double y3 = dots[2].get_y();

    return point((x2 - x1) / 2.0, (y3 - y2) / 2.0);
}
