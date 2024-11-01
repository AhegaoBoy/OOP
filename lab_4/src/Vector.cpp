#include "Vector.h"

template<typename T>
Vector<T>::Vector(Vector &&other) noexcept: _size(other._size), _capacity(other._capacity), _array(other._array)
{
    other._size = 0;
    other._capacity = 0;
    other._array = nullptr;
}

template<typename T>
Vector<T>::Vector(const Vector &other) noexcept : _size(other._size), _capacity(other._capacity)
{
    _array = new Figure<T>* [_capacity];
    std::memcpy(_array, other._array, _size);
}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector &other) noexcept
{
    if(this != &other)
    {
        _size = other._size;
        _capacity = other._capacity;

        _array = new Figure<T>* [_capacity];
        std::memcpy(_array, other._array, _capacity);
    }
    return *this;
}

template<typename T>
Vector<T>& Vector<T>::operator=(Vector &&other) noexcept
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

template<typename T>
Vector<T>::Vector() : _array(nullptr), _size(0), _capacity(1)
{
    _array = new Figure<T>*[_capacity];
    for (int i = 0; i < _capacity; i++)
        _array[i] = nullptr;
}

template<typename T>
void Vector<T>::resize(int new_size)
{
    Figure<T>** tmp = new Figure<T>*[new_size];
    for (int i = 0; i < new_size; i++)
        tmp[i] = nullptr;

    for (int i = 0; i < _size; i++)
        tmp[i] = _array[i];

    delete [] _array;
    _array = tmp;
    _capacity = new_size;
}

template<typename T>
size_t Vector<T>::size() const
{
    return _size;
}

template<typename T>
void Vector<T>::push_back(Figure<T>* val)
{
    if (_size == _capacity)
    {
        _capacity<<=1;
        resize(_capacity);
    }
    _array[_size++] = val;
}

template<typename T>
Figure<T>* & Vector<T>::operator[](int idx)
{
    return _array[idx];
}

template<typename T>
void Vector<T>::remove(int idx){
    if (idx < 0 || idx > _size) {
        throw std::invalid_argument("Index out of range");
    }

    Figure<T>** new_buf = new Figure<T>*[_capacity];

    for (int i = 0; i < idx; i++)
        new_buf[i] = _array[i];

    for (int i = idx; i < _size - 1; i++)
        new_buf[i] = _array[i + 1];


    delete [] _array;
    _array = new_buf;
    _size--;
}

template<typename T>
Vector<T>::~Vector()
{
    _size = 0;
    _capacity = 0;
    delete [] _array;
    _array = nullptr;
}