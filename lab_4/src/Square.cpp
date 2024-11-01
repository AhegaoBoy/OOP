#include "Square.h"
#include "Point.h"

template<typename T>
square<T>::square(point<T> arr[ANGLES]) : Figure<T>(arr)
{

}

template<typename T>
square<T>::square(const square &other) noexcept
{
    this->dots = new point<T>[ANGLES];
    std::memcpy(this->dots, other.dots, ANGLES);
}

template<typename T>
square<T> &square<T>::operator=(const square &other) noexcept
{
    if(this != &other)
    {
        this->dots = new point<T>[ANGLES];
        std::memcpy(this->dots, other.dots, ANGLES);
    }
    return *this;
}

template<typename T>
square<T>::square(square &&other) noexcept
{
    this->dots = other.dots;
    other.dots = nullptr;
}

template<typename T>
square<T>& square<T>::operator=(square &&other) noexcept
{
    if(this != &other)
    {
        this->dots = other.dots;
        other.dots = nullptr;
    }
    return *this;
}

template<typename T>
double square<T>::area() const
{
    return point<T>::metrics(this->dots[0], this->dots[1]) * point<T>::metrics(this->dots[1], this->dots[2]);
}

template<typename T>
point<T> square<T>::center() const
{
    double x1 = this->dots[0].get_x();
    double x2 = this->dots[1].get_x();
    double y2 = this->dots[2].get_y();
    double y3 = this->dots[2].get_y();

    return point((x2 - x1) / 2.0, (y3 - y2) / 2.0);
}

