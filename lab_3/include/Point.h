#ifndef LAB_3_POINT_H
#define LAB_3_POINT_H
#define angles 4
#include <ostream>
#include <istream>
#include <cmath>

class point
{
private:
    double x;
    double y;

public:
    point() : x(0.), y(0.){};
    explicit point(double x1, double x2) : x(x1), y(x2){};

    static double metrics(point const& p1, point const& p2);

    friend std::ostream& operator<<(std::ostream& os, point const& value);
    friend std::istream& operator>>(std::istream& os, point& value);

    double get_x() const
    {
        return x;
    }

    double get_y() const
    {
        return y;
    }



};

std::ostream& operator<<(std::ostream& os, point const& value)
{
    return os;
}

std::istream& operator>>(std::istream& is, point& value)
{
    return is;
}

#endif //LAB_3_POINT_H
