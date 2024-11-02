#ifndef LAB_4_POINT_H
#define LAB_4_POINT_H

#include <iostream>

template<typename T>
class Point
{
public:
    T x_{};
    T y_{};

public:

    template<class F>
    friend Point<F> operator + (const Point<F>& t, const Point<F>& other);
    template<class F>
    friend Point<F> operator - (const Point<F>& t, const Point<F>& other);
    template<class F>
    friend bool operator == (const Point<F>& t, const Point<F>& other);
    template<class F>
    friend bool operator != (const Point<F>& t, const Point<F>& other);

    template<class F>
    friend std::istream& operator >> (std::istream& is, Point<F>& p);
    template<class F>
    friend std::ostream& operator << (std::ostream& os, const Point<F>& p);

public:
    Point();
    Point(const Point<T>& other);
    Point(T x, T y);

    Point& operator =(const Point& other);


};



template<typename T>
Point<T>::Point() : x_{0}, y_{0} {}

template<typename T>
Point<T>::Point(T x, T y): x_{x}, y_{y} {}

template<typename T>
Point<T>::Point(const Point<T> &other) : x_(other.x_), y_(other.y_) {}

template<typename T>
Point<T> operator + (const Point<T>& t, const Point<T>& other)
        {
    return Point<T>(t.x_ + other.x_, t.y_ + other.y_);
}

template<typename T>
Point<T> operator - (const Point<T>& t, const Point<T>& other)
        {
    return Point<T>(t.x_ - other.x_, t.y_ - other.y_);
}

template<typename T>
bool operator == (const Point<T>& t, const Point<T>& other)
{
    return (t.x_ == other.x_) && (t.y_ == other.y_);
}

template<typename T>
bool operator != (const Point<T> &t, const Point<T> &other)
{
    return (t.x_ != other.x_) || (t.y_ != other.y_);
}

template<typename T>
Point<T>& Point<T>::operator = (const Point<T> &other)
        {
    if (this != &other) {
        x_ = other.x_;
        y_ = other.y_;
    }
    return *this;
}

template<typename T>
std::istream& operator >> (std::istream &is, Point<T> &p){
    T x, y;
    is >> x >> y;
    p.x_ = x;
    p.y_ = y;
    return is;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Point<T>& p){
    os << "x  " << p.x_ << ", y  " << p.y_;
    return os;
}
#endif
