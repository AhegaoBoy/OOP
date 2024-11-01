#include "decimal.h"

decimal::decimal() : length(0), numbers(nullptr){}

decimal::decimal(const size_t &size, unsigned char el)
{

}

decimal::decimal(const std::string &init)
{
    size_t ind = 0;

    while(init[ind] == '0')
        ind++;
    length = init.length() - ind;
    numbers = new unsigned char [length];

    for(size_t i = ind; i <= init.length(); ++i)
    {
        if(init[ind] < '0' || init[ind] > '9')
            throw std::logic_error("There's digit out of range [0, 9]");
        numbers[i - ind] = init[i];
    }
}

decimal::decimal(const std::initializer_list<unsigned char> &init)
{
    size_t zeros = 0;
    auto iter = init.begin();

    while(iter != init.end())
    {
        if(*iter != '0')
        {
            --iter;
            break;
        }
        ++zeros;
    }

    length = init.size() - zeros;
    numbers = new unsigned char[length];
    zeros = 0;
    while(iter != init.end())
    {
        if(*iter < '0' || *iter > '9')
            throw std::logic_error("There's digit out of range [0, 9]");
        numbers[zeros++] = *iter;
    }
}

decimal &decimal::operator=(const decimal &other) noexcept
{
    if(this != &other)
    {
        length = other.length;
        numbers = new unsigned char[length];
        std::memcpy(numbers,other.numbers, length);
    }
    return *this;
}

decimal::decimal(const decimal &other) noexcept : length(other.length)
{
    numbers = new unsigned char[length];
    std::memcpy(numbers, other.numbers, length);
}

decimal::decimal(decimal &&other) noexcept : length(other.length), numbers(other.numbers)
{
    other.length = 0;
    other.numbers = nullptr;
}

decimal &decimal::operator=(decimal &&other) noexcept
{
    if(this != &other)
    {
        length = other.length;
        numbers = other.numbers;

        other.length = 0;
        other.numbers = nullptr;
    }
    return *this;
}

decimal::~decimal()
{
    delete[] numbers;
}

decimal &decimal::operator+=(const decimal &other)
{
    int final_length = std::max(length, other.length) + 1;
    std::string res(final_length, '0');

    for (int i = 0; i < final_length - 1; i++) {
        int sum = ((i < length) ? numbers[i] - '0' : 0) + ((i < other.length) ? other.numbers[i] - '0' : 0);
        res[i + 1] += (res[i] - '0' + sum) / base;
        res[i] = (res[i] - '0' + sum) % base + '0';
    }

    reverse(res.begin(), res.end());

    *this = decimal(res);
    return *this;
}

decimal decimal::operator+(const decimal &other)
{
    return decimal(*this) += other;
}

decimal &decimal::operator-=(const decimal &other)
{
    if (*this < other)
        throw std::logic_error("Error occured. Result must be positive.");


    if (*this == other)
        return *this = decimal("0");

    int final_length = std::max(length, other.length);
    std::string res(final_length, '0');

    for (int i = 0; i < final_length - 1; i++) {
        res[i] += numbers[i] - '0' - ((i < other.length) ? other.numbers[i] - '0' : 0);
        if (res[i] - '0' < 0) {
            res[i] += base;
            res[i + 1] -= 1;
        }
    }
    res[final_length - 1] += numbers[final_length - 1] - '0' - ((final_length == other.length) ? other.numbers[final_length - 1] - '0' : 0);

    reverse(res.begin(), res.end());

    *this = decimal(res);
    return *this;
}

decimal decimal::operator-(const decimal &other)
{
    return decimal(*this) -= other;
}

bool decimal::operator<(const decimal &other) const
{
    if (length != other.length)
        return length < other.length;
    size_t i = length;
    
    while(i--)
        if (numbers[i] != other.numbers[i])
            return numbers[i] < other.numbers[i];
    return false;
}

bool decimal::operator>(const decimal &other) const
{
    return !(*this < other);
}

bool decimal::operator==(const decimal &other) const
{
    if (length != other.length)
        return false;

    for (int i = 0; i < length; i++)
        if (numbers[i] != other.numbers[i])
            return false;
    return true;
}

bool decimal::operator!=(const decimal &other) const
{
    return !(*this == other);
}

std::ostream& operator<<(std::ostream os, decimal const& value)
{
    size_t i = value.length;
    while(i--)
        os<<value.numbers[i];
    return os;
}
