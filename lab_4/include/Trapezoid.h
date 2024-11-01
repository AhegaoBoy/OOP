#ifndef LAB_4_TRAPEZOID_H
#define LAB_4_TRAPEZOID_H
#include "Figure.h"

template<typename T>
class trapezoid : public Figure<T>
{
    trapezoid() = default;
    trapezoid(point<T> arr[ANGLES]);
    [[nodiscard]] double area() const override;
    point<T> center() const override;
    operator double() override;

    trapezoid& operator=(trapezoid const& other) noexcept;
    trapezoid(trapezoid const& other) noexcept;
    trapezoid& operator=(trapezoid &&other) noexcept;
    trapezoid(trapezoid &&other) noexcept;
    ~trapezoid(){};
};
#endif //LAB_4_TRAPEZOID_H
