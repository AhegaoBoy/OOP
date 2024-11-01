#include "Vector.h"


Vector::Vector(Vector &&other) noexcept: _size(other._size), _capacity(other._capacity), _array(other._array)
{
    other._size = 0;
    other._capacity = 0;
    other._array = nullptr;
}

Vector::Vector(const Vector &other) noexcept : _size(other._size), _capacity(other._capacity)
{
    _array = new Figure * [_capacity];
    std::memcpy(_array, other._array, _size);
}

Vector& Vector::operator=(const Vector &other) noexcept
{
    if(this != &other)
    {
        _size = other._size;
        _capacity = other._capacity;

        _array = new Figure * [_capacity];
        std::memcpy(_array, other._array, _capacity);
    }
    return *this;
}

Vector& Vector::operator=(Vector &&other) noexcept
{
    if(this != &other)
    {
        _size = other._size;
        _capacity = other._capacity;
        _array = other._array;

        other._array = nullptr;
        }
    return *this;
}
Vector::Vector() : _array(nullptr), _size(0), _capacity(1)
{
    _array = new Figure*[_capacity];
    for (int i = 0; i < _capacity; i++)
        _array[i] = nullptr;
}


void Vector::resize(int new_size)
{
    Figure** tmp = new Figure*[new_size];
    for (int i = 0; i < new_size; i++)
        tmp[i] = nullptr;

    for (int i = 0; i < _size; i++)
        tmp[i] = _array[i];

    delete [] _array;
    _array = tmp;
    _capacity = new_size;
}

size_t Vector::size() const
{
    return _size;
}

void Vector::push_back(Figure* val)
{
    if (_size == _capacity)
    {
        _capacity<<=1;
        resize(_capacity);
    }
    _array[_size++] = val;
}

Figure* & Vector::operator[](int idx)
{
    return _array[idx];
}

void Vector::remove(int idx){
    if (idx < 0 || idx > _size) {
        throw std::invalid_argument("Index out of range");
    }

    Figure** new_buf = new Figure*[_capacity];

    for (int i = 0; i < idx; i++)
        new_buf[i] = _array[i];

    for (int i = idx; i < _size - 1; i++)
        new_buf[i] = _array[i + 1];


    delete [] _array;
    _array = new_buf;
    _size--;
}

Vector::~Vector(){
    _size = 0;
    _capacity = 0;
    delete [] _array;
    _array = nullptr;
}