#ifndef LAB_4_HEXAGON_H
#define LAB_4_HEXAGON_H

#include "figure.h"
#include "point.h"
#include <iostream>

using namespace std;

template <class T>
class Hexagon : public Figure<T>{


    friend ostream& operator << (ostream& os, const Hexagon& f);

    friend istream& operator >> (istream& is, Hexagon& f);

public:
    Hexagon();
    Hexagon(Point<T>& p1, Point<T>& p2, Point<T>& p3, Point<T>& p4, Point<T>& p5, Point<T>& p6);

    virtual T square() const override;
    virtual Point<T> center() const override;

    Hexagon<T>& operator = (const Hexagon<T> &other);
    Hexagon<T>& operator = (Hexagon<T> &&other);
    bool operator == (const Hexagon<T> &other);
    virtual operator double() const override;

    ~Hexagon(){};

private:
    static const size_t angles_ = 6;
    Point<T> po[angles_];

};




template <class T>
Hexagon<T>::Hexagon() : po{Point<T>(), Point<T>(), Point<T>(), Point<T>()} {}

template <class T>
Hexagon<T>::Hexagon(Point<T>& p1, Point<T>& p2, Point<T>& p3, Point<T>& p4, Point<T>& p5, Point<T>& p6) :
        po{p1, p2, p3, p4, p5, p6}  {}

template <class T>
Point<T> Hexagon<T>::center() const {
    T x = 0, y = 0;
    for(size_t i = 0; i < angles_; ++i){
        x += po[i].x_;
        y += po[i].y_;
    }
    return Point<T>(x / 6.0, y / 6.0);
}

template <class T>
T Hexagon<T>::square() const {
    T x1 = po[0].x_; T y1 = po[0].y_;
    T x2 = po[1].x_; T y2 = po[1].y_;
    T x3 = po[2].x_; T y3 = po[2].y_;
    T x4 = po[3].x_; T y4 = po[3].y_;
    T x5 = po[4].x_; T y5 = po[4].y_;
    T x6 = po[5].x_; T y6 = po[5].y_;

    T S = abs(x1*y2 + x2*y3 + x3*y4 + x4*y5 + x5*y6 + x6*y1 - x2*y1 - x3*y2 - x4*y3 - x5*y4 - x6*y5 - x1*y6) / 2.0;
    return S;
}

template <class T>
Hexagon<T>& Hexagon<T>::operator = (const Hexagon<T> &other){
    if (this == &other) {
        return *this;
    }

    for(size_t i = 0; i < angles_; ++i){
        po[i] = other.po[i];
    }

    return *this;
}

template <class T>
Hexagon<T>& Hexagon<T>::operator = (Hexagon<T> &&other){
    if (this == &other) {
        return *this;
    }

    for(size_t i = 0; i < angles_; ++i){
        po[i] = move(other.po[i]);
    }

    return *this;
}

template <class T>
bool Hexagon<T>::operator == (const Hexagon<T>& other){
    for(size_t i = 0; i < angles_; ++i){
        if(po[i] != other.po[i]){
            return false;
        }
    }
    return true;
}

template <class T>
ostream& operator << (ostream& os, const Hexagon<T>& hex){
    for(size_t i = 0; i < Hexagon<T>::angles_; ++i){
        os << hex.po[i] << endl;
    }
    return os;
}

template <class T>
istream& operator >> (istream& is, Hexagon<T>& hex) {
    cout << "Введите координаты шестиугольника через пробел следующим образом: x1 y1 ... x6 y6:" << endl;
    for (size_t i = 0; i < Hexagon<T>::angles_; ++i) {
        is >> hex.po[i];
    }
    return is;
}

template <class T>
Hexagon<T>::operator double() const{
    return square();
}
#endif
