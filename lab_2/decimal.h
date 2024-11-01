#ifndef LAB_2_DECIMAL_H
#define LAB_2_DECIMAL_H
#include <initializer_list>
#include <string>
#include <ostream>
//#include <>
class decimal
{
public:
    decimal();
    decimal(size_t const& size, unsigned char el = 0);
    decimal(std::initializer_list<unsigned char> const& init);
    decimal(std::string const& init);


    decimal& operator=(decimal const& other) noexcept;
    decimal(decimal const& other) noexcept;
    decimal& operator=(decimal &&other) noexcept;
    decimal(decimal &&other) noexcept;
    virtual ~decimal();

    decimal& operator+=(decimal const& other);
    decimal operator+(decimal const& other);

    decimal& operator-=(decimal const& other);
    decimal operator-(decimal const& other);

    bool operator<(decimal const& other) const;
    bool operator>(decimal const& other) const;
    bool operator==(decimal const& other) const;
    bool operator!=(decimal const& other) const;

    friend std::ostream& operator<<(std::ostream, decimal const&);

private:
    size_t length;
    unsigned char const base = 10;
    unsigned char* numbers;

};
#endif //LAB_2_DECIMAL_H
