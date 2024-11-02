#ifndef LAB_4_PENTAGON_H
#define LAB_4_PENTAGON_H


#include "figure.h"
#include <iostream>

using namespace std;

template <class T>
class Pentagon : public Figure<T>{


    friend std::ostream& operator << (std::ostream& os, const Pentagon& f);

    friend std::istream& operator >> (std::istream& is, Pentagon& f);

public:
    Pentagon();
    Pentagon(Point<T>& p1, Point<T>& p2, Point<T>& p3, Point<T>& p4, Point<T>& p5);

    virtual T square() const override;
    virtual Point<T> center() const override;

    Pentagon<T>& operator = (const Pentagon<T> &other);
    Pentagon<T>& operator = (Pentagon<T> &&other);
    bool operator == (const Pentagon<T> &other);
    virtual operator double() const override;

    ~Pentagon(){};

private:
    static const size_t angles_ = 5;
    Point<T> po[angles_];
};




template <class T>
Pentagon<T>::Pentagon() : po{Point<T>(), Point<T>(), Point<T>(), Point<T>(), Point<T>()} {}

template <class T>
Pentagon<T>::Pentagon(Point<T>& p1, Point<T>& p2, Point<T>& p3, Point<T>& p4, Point<T>& p5) :
        po{p1, p2, p3, p4, p5} {}

template <class T>
Point<T> Pentagon<T>::center() const {
    T x = 0, y = 0;
    for(size_t i = 0; i < angles_; ++i){
        x += po[i].x_;
        y += po[i].y_;
    }
    return Point<T>(x / 5.0, y / 5.0);
}

template <class T>
T Pentagon<T>::square() const {
    T x1 = po[0].x_; T y1 = po[0].y_;
    T x2 = po[1].x_; T y2 = po[1].y_;
    T x3 = po[2].x_; T y3 = po[2].y_;
    T x4 = po[3].x_; T y4 = po[3].y_;
    T x5 = po[4].x_; T y5 = po[4].y_;

    T S = abs(x1*y2 + x2*y3 + x3*y4 + x4*y5 + x5*y1 - y1*x2 - y2*x3 - y3*x4 - y4*x5 - y5 *x1)/2.0;
    return S;
}

template <class T>
Pentagon<T>& Pentagon<T>::operator = (const Pentagon<T> &other){
    if (this == &other) {
        return *this;
    }

    for(size_t i = 0; i < angles_; ++i){
        po[i] = other.po[i];
    }

    return *this;
}

template <class T>
Pentagon<T>& Pentagon<T>::operator = (Pentagon<T> &&other){
    if (this == &other) {
        return *this;
    }


    for(size_t i = 0; i < angles_; ++i){
        po[i] = move(other.po[i]);
    }

    return *this;
}

template <class T>
bool Pentagon<T>::operator == (const Pentagon<T> &other){
    for(size_t i = 0; i < angles_; ++i){
        if(po[i] != other.po[i]){
            return false;
        }
    }
    return true;
}

template <class T>
ostream& operator << (ostream& os, const Pentagon<T>& pent){
    for(size_t i = 0; i < Pentagon<T>::angles_; ++i){
        os << pent.po[i] << endl;
    }
    return os;

}

template <class T>
istream& operator >> (istream& is, Pentagon<T>& pent){
    cout << "Input pentagon angles coordinates like: x1 y1 ... x5 y5:" << endl;
    for(size_t i = 0; i < Pentagon<T>::angles_; ++i){
        is >> pent.po[i];
    }
    return is;
}

template <class T>
Pentagon<T>::operator double() const{
    return square();
}

#endif
