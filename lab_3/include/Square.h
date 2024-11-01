#ifndef LAB_3_SQUARE_H
#define LAB_3_SQUARE_H
#include "Figure.h"

class square : public Figure
{
    square() = default;
    square(point arr[angles]);
    [[nodiscard]] double area() const override;
    point center() const override;
    operator double() override;

    square& operator=(square const& other) noexcept;
    square(square const& other) noexcept;
    square& operator=(square &&other) noexcept;
    square(square &&other) noexcept;
    ~square(){};
};
#endif //LAB_3_SQUARE_H
