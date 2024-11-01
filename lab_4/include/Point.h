#ifndef LAB_4_POINT_H
#define LAB_4_POINT_H

#define ANGLES 4
#include <ostream>

template<class T>
class point
{
private:
    T x;
    T y;
public:
    point() : x(0), y(0){}
    explicit point(T x1, T x2) : x(x1), y(x2){};

    static double metrics(point const& p1, point const& p2);

    friend std::ostream& operator<<(std::ostream& os, point const & value);
    friend std::istream& operator>>(std::istream& is, point& value);

};
template<typename T>
std::ostream& operator<<(std::ostream& os, point<T> const& value)
{
    return os;
}

template<typename T>
std::istream& operator>>(std::istream& is, point<T>& value)
{
    return is;
}
#endif //LAB_4_POINT_H
