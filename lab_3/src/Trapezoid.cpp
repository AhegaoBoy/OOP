#include "Trapezoid.h"
#include "Point.h"

trapezoid::trapezoid(point arr[angles]) : Figure(arr)
{

}

trapezoid::trapezoid(const trapezoid &other) noexcept
{
    dots = new point[angles];
    std::memcpy(dots, other.dots, angles);
}

trapezoid &trapezoid::operator=(const trapezoid &other) noexcept
{
    if(this != &other)
    {
        dots = new point[angles];
        std::memcpy(dots, other.dots, angles);
    }
    return *this;
}

trapezoid::trapezoid(trapezoid &&other) noexcept
{
    dots = other.dots;
    other.dots = nullptr;
}

trapezoid& trapezoid::operator=(trapezoid &&other) noexcept
{
    if(this != &other)
    {
        dots = other.dots;
        other.dots = nullptr;
    }
    return *this;
}

double trapezoid::area() const
{
    return point::metrics(dots[0], dots[1]) * point::metrics(dots[1], dots[2]);
}

point trapezoid::center() const
{
    double x1 = dots[0].get_x();
    double x2 = dots[1].get_x();
    double y2 = dots[2].get_y();
    double y3 = dots[2].get_y();

    return point((x2 - x1) / 2.0, (y3 - y2) / 2.0);
}