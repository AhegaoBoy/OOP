#ifndef LAB_4_VECTOR_H
#define LAB_4_VECTOR_H

#include <iostream>
#include <memory>
#include "figure.h"

using namespace std;

template<class T>
class Vector
{
private:
    unique_ptr<unique_ptr<Figure<T>>[]> buf;
    int size_;
    int cap;

public:
    Vector();
    void resize(int new_size);
    int  size() const;
    void push_back(unique_ptr<Figure<T>> val);
    void remove(int idx);
    unique_ptr<Figure<T>>& get(int idx);

    ~Vector();

};





template<class T>
Vector<T>::Vector() : buf(nullptr), size_(0), cap(0){}

template<class T>
void Vector<T>::resize(int new_size) {
    unique_ptr<unique_ptr<Figure<T>>[]> tmp = make_unique<unique_ptr<Figure<T>>[]>(new_size);
    for (int i = 0; i < size_; i++) {
        tmp[i] = move(buf[i]);
    }
    buf = move(tmp);
    cap = new_size;
}

template<class T>
int Vector<T>::size() const{
    return size_;
}

template<class T>
void Vector<T>::push_back(unique_ptr<Figure<T>> val){
    if (size_ == cap) {
    resize(cap + 1);
    }
    buf[size_] = move(val);
    size_++;
}

template <class T>
unique_ptr<Figure<T>>& Vector<T>::get(int idx){
    if (idx < 0 || idx > size_) {
        throw invalid_argument("Index out of range");
    }
    else{
        return buf[idx];
    }
}

template<class T>
void Vector<T>::remove(int idx){
    if (idx < 0 || idx > size_) {
        throw invalid_argument("Index out of range");
    }

    for (int i = idx; i < size_ - 1; i++) {
        buf[i] = move(buf[i + 1]);
    }

    size_--;
}

template<class T>
Vector<T>::~Vector(){}

#endif
