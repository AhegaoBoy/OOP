#ifndef LAB_3_RECTANGLE_H
#define LAB_3_RECTANGLE_H
#include "Figure.h"


class rectangle : public Figure
{
public:
    rectangle() = default;
    rectangle(point arr[angles]);
    [[nodiscard]] double area() const override;
    point center() const override;
    operator double() override;

    rectangle& operator=(rectangle const& other) noexcept;
    rectangle(rectangle const& other) noexcept;
    rectangle& operator=(rectangle &&other) noexcept;
    rectangle(rectangle &&other) noexcept;
    ~rectangle(){};
};

#endif //LAB_3_RECTANGLE_H
