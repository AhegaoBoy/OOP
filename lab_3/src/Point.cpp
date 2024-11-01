#include "Point.h"

double point::metrics(const point &p1, const point &p2)
{
    return std::sqrt(
            (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y)
            );
}

