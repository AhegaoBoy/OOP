#include "Rectangle.h"
#include "Point.h"

template<typename T>
rectangle<T>::rectangle(point<T> arr[ANGLES]) : Figure<T>(arr)
{

}

template<typename T>
rectangle<T>::rectangle(const rectangle &other) noexcept
{
    this->dots = new point<T>[ANGLES];
    std::memcpy(this->dots, other.dots, ANGLES);
}

template<typename T>
rectangle<T> &rectangle<T>::operator=(const rectangle &other) noexcept
{
    if(this != &other)
    {
        this->dots = new point[ANGLES];
        std::memcpy(this->dots, other.dots, ANGLES);
    }
    return *this;
}

template<typename T>
rectangle<T>::rectangle(rectangle<T> &&other) noexcept
{
    this->dots = other.dots;
    other.dots = nullptr;
}

template<typename T>
rectangle<T>& rectangle<T>::operator=(rectangle &&other) noexcept
{
    if(this != &other)
    {
        this->dots = other.dots;
        other.dots = nullptr;
    }
    return *this;
}

template<typename T>
double rectangle<T>::area() const
{
    return point<T>::metrics(this->dots[0], this->dots[1]) * point<T>::metrics(this->dots[1], this->dots[2]);
}

template<typename T>
point<T> rectangle<T>::center() const
{
    double x1 = dots[0].get_x();
    double x2 = dots[1].get_x();
    double y2 = dots[2].get_y();
    double y3 = dots[2].get_y();

    return point((x2 - x1) / 2.0, (y3 - y2) / 2.0);
}
