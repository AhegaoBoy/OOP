#ifndef LAB_4_RHOMB_H
#define LAB_4_RHOMB_H


#include "figure.h"
#include <iostream>

using namespace std;

template <class T>
class Rhomb : public Figure<T>{

private:
    static const size_t angles_ = 4;
    Point<T> po[angles_];

    friend std::ostream& operator<<(std::ostream& os, const Rhomb& f);

    friend std::istream& operator>>(std::istream& is, Rhomb& f);

public:
    Rhomb();
    Rhomb(Point<T>& p1, Point<T>& p2, Point<T>& p3, Point<T>& p4);

    virtual T square() const override;
    virtual Point<T> center() const override;

    Rhomb<T>& operator = (const Rhomb<T> &other);
    Rhomb<T>& operator = (Rhomb<T> &&other);
    bool operator == (const Rhomb<T> &other);
    virtual operator double() const override;

    ~Rhomb(){};


};




template <class T>
Rhomb<T>::Rhomb() : po{Point<T>(), Point<T>(), Point<T>(), Point<T>()} {}

template <class T>
Rhomb<T>::Rhomb(Point<T>& p1, Point<T>& p2, Point<T>& p3, Point<T>& p4) : po{p1, p2, p3, p4}  {}

template <class T>
Point<T> Rhomb<T>::center() const {
    T x = 0, y = 0;
    for(size_t i = 0; i < angles_; ++i){
        x += po[i].x_;
        y += po[i].y_;
    }
    return Point<T>(x / 4.0, y / 4.0);
}

template <class T>
T Rhomb<T>::square() const {
    T x1 = po[0].x_; T y1 = po[0].y_;
    T x2 = po[1].x_; T y2 = po[1].y_;
    T x3 = po[2].x_; T y3 = po[2].y_;
    T x4 = po[3].x_; T y4 = po[3].y_;

    T S = abs(x1*y2 + x2*y3 + x3*y4 + x4*y1 - x2*y1 - x3*y2 - x4*y3 - x1*y4) / 2.0;
    return S;
}

template <class T>
Rhomb<T>& Rhomb<T>::operator = (const Rhomb<T> &other){
    if (this == &other) {
        return *this;
    }

    for(size_t i = 0; i < angles_; ++i){
        po[i] = other.po[i];
    }

    return *this;
}

template <class T>
Rhomb<T>& Rhomb<T>::operator = (Rhomb<T> &&other){
    if (this == &other) {
        return *this;
    }

    for(size_t i = 0; i < angles_; ++i){
        po[i] = move(other.po[i]);
    }

    return *this;
}

template <class T>
bool Rhomb<T>::operator == (const Rhomb<T>& other){
    for(size_t i = 0; i < angles_; ++i){
        if(po[i] != other.po[i]){
            return false;
        }
    }
    return true;
}

template <class T>
ostream& operator << (ostream& os, const Rhomb<T>& rh){
    for(size_t i = 0; i < Rhomb<T>::angles_; ++i){
        os << rh.po[i] << endl;
    }
    return os;
}

template <class T>
istream& operator >> (istream& is, Rhomb<T>& rh) {
    cout << "Input rhombus coordinates like: x1 y1 ... x4 y4:" << endl;
    for (size_t i = 0; i < Rhomb<T>::angles_; ++i) {
        is >> rh.po[i];
    }
    return is;
}

template <class T>
Rhomb<T>::operator double() const{
    return square();
}
#endif
