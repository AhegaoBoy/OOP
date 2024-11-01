#ifndef LAB_4_FIGURE_H
#define LAB_4_FIGURE_H
#include "Point.h"
template<class T>
class Figure {
public:
    Figure() = default;

    Figure(point<T> const *arr) {
        dots = new point<T>[ANGLES];
        std::memcpy(dots, arr, ANGLES);
    }

    virtual double area() const = 0;

    virtual point<T> center() const = 0;

    virtual operator double() = 0;

    virtual ~Figure() = 0;

    friend std::ostream &operator<<(std::ostream &os, Figure const &value);

    friend std::istream &operator>>(std::istream &is, Figure &value);

protected:
    point<T> *dots;
};

template<typename T>
std::ostream& operator<<(std::ostream& os, Figure<T> const&value)
{
    return os;
}
template<typename T>
std::istream& operator>>(std::istream& is, Figure<T>& value)
{
    return is;
}
#endif //LAB_4_FIGURE_H
