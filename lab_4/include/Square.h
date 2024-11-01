#ifndef LAB_4_SQUARE_H
#define LAB_4_SQUARE_H
#include "Figure.h"

template<class T>
class square : public Figure<T>
{
    square() = default;
    square(point<T> arr[ANGLES]);
    [[nodiscard]] double area() const override;
    point<T> center() const override;
    operator double() override;

    square& operator=(square const& other) noexcept;
    square(square const& other) noexcept;
    square& operator=(square &&other) noexcept;
    square(square &&other) noexcept;
    ~square(){};
};
#endif //LAB_4_SQUARE_H
