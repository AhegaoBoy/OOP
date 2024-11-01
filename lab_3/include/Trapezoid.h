#ifndef LAB_3_TRAPEZOID_H
#define LAB_3_TRAPEZOID_H
#include "Figure.h"

class trapezoid : public Figure
{
    trapezoid() = default;
    trapezoid(point arr[angles]);
    [[nodiscard]] double area() const override;
    point center() const override;
    operator double() override;

    trapezoid& operator=(trapezoid const& other) noexcept;
    trapezoid(trapezoid const& other) noexcept;
    trapezoid& operator=(trapezoid &&other) noexcept;
    trapezoid(trapezoid &&other) noexcept;
    ~trapezoid(){};
};
#endif //LAB_3_TRAPEZOID_H
