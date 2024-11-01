#ifndef LAB_4_VECTOR_H
#define LAB_4_VECTOR_H
#include "Figure.h"

template<class T>
class Vector
{
private:
    size_t _size;
    size_t _capacity;
    Figure<T>** _array;

public:
    Vector();
    void resize(int new_size);
    size_t size() const;
    void push_back(Figure<T>* val);
    void remove(int ind);
    Figure<T>* & operator[] (int idx);

    Vector(Vector const& other) noexcept;
    Vector(Vector &&other) noexcept;
    Vector& operator=(Vector const& other) noexcept;
    Vector& operator=(Vector && other) noexcept;
    ~Vector();
};
#endif //LAB_4_VECTOR_H
