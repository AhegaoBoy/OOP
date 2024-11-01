#ifndef LAB_4_RECTANGLE_H
#define LAB_4_RECTANGLE_H
#include "Figure.h"

template<class T>
class rectangle : public Figure<T>
{
public:
    rectangle() = default;
    rectangle(point<T> arr[ANGLES]);
    [[nodiscard]] double area() const override;
    point<T> center() const override;
    operator double() override;

    rectangle& operator=(rectangle const& other) noexcept;
    rectangle(rectangle const& other) noexcept;
    rectangle& operator=(rectangle &&other) noexcept;
    rectangle(rectangle &&other) noexcept;
    ~rectangle(){};
};
#endif //LAB_4_RECTANGLE_H
