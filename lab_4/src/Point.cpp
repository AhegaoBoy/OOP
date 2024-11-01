#include "Point.h"
template<typename T>
double point<T>::metrics(const point<T> &p1, const point<T> &p2)
{
    return std::sqrt(
            (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y)
    );
}