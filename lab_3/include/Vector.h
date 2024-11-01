#ifndef LAB_3_VECTOR_H
#define LAB_3_VECTOR_H
#include "Figure.h"

class Vector
{
private:
    size_t _size;
    size_t _capacity;
    Figure** _array;

public:
    Vector();
    void resize(int new_size);
    size_t size() const;
    void push_back(Figure* val);
    void remove(int ind);
    Figure* & operator[] (int idx);

    Vector(Vector const& other) noexcept;
    Vector(Vector &&other) noexcept;
    Vector& operator=(Vector const& other) noexcept;
    Vector& operator=(Vector && other) noexcept;
    ~Vector();
};
#endif //LAB_3_VECTOR_H
