#include <algorithm>
#include <cstring>
#include "decimal.h"

decimal::decimal() : length(0), numbers(nullptr){}

decimal::decimal(const size_t &size, unsigned char el)
{

}

decimal::decimal(const std::string &init)
{
    size_t ind = 0;

    if(init != "0")
    {
        while(init[ind] == '0')
            ind++;
    }

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
        numbers = new unsigned char[length + 1];
        memcpy(numbers,other.numbers, length);
        numbers[length + 1] = '\0';
    }
    return *this;
}

decimal::decimal(const decimal &other) noexcept : length(other.length)
{
    numbers = new unsigned char[length];
    memcpy(numbers, other.numbers, length);
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
    std::string res;



    int i = length - 1;
    int j = other.length - 1;
    int carry = 0;


    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0)
            sum += numbers[i--] - '0';

        if (j >= 0)
            sum += other.numbers[j--] - '0';



        carry = sum / 10;
        res.push_back((sum % 10) + '0');
    }

    std::reverse(res.begin(), res.end());




    *this = decimal(res);
    return *this;
}

decimal decimal::operator+(const decimal &other)
{
    return decimal(*this) += other;
}

decimal& decimal::operator-=(const decimal& other)
{
    if((!this->numbers || this->numbers[0] == '0') && other.numbers)
    {
        delete[] numbers;
        length = other.length;
        numbers = new unsigned char[length];
        memcpy(numbers, other.numbers, length);
        return *this;
    }

    if((!other.numbers || other.numbers[0] == '0') && numbers)
    {
        return *this;
    }

    std::string first(reinterpret_cast<const char*>(this->numbers));
    std::string second(reinterpret_cast<const char*>(other.numbers));

    if (first == second) {

        std::strcpy(reinterpret_cast<char*>(this->numbers), "0");
        return *this;
    }

    bool isNegative = false;


    if (first.size() < second.size() || (first.size() == second.size() && first < second)) {
        std::swap(first, second);
        isNegative = true;
    }

    std::string result;
    int i = length - 1;
    int j = other.length - 1;
    int borrow = 0;


    while (i >= 0) {
        int digit1 = first[i--] - '0' - borrow;
        int digit2 = j >= 0 ? second[j--] - '0' : 0;

        if (digit1 < digit2) {
            digit1 += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        result.push_back((digit1 - digit2) + '0');
    }


    while (result.size() > 1 && result.back() == '0') {
        result.pop_back();
    }


    if (isNegative) {
        result.push_back('-');
    }


    std::reverse(result.begin(), result.end());


    strcpy(reinterpret_cast<char*>(this->numbers), result.c_str());
    this->length = result.size();

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

bool decimal::operator>=(const decimal &other) const
{
    if (length != other.length)
        return length > other.length;

    for (int i = 0; i < length; i++)
        if (numbers[i] < other.numbers[i])
            return false;
    return true;
}

bool decimal::operator<=(const decimal &other) const
{
    if (length != other.length)
        return length < other.length;

    for (int i = 0; i < length; i++)
        if (numbers[i] > other.numbers[i])
            return false;
    return true;
}

std::ostream& operator<<(std::ostream os, decimal const& value)
{
    size_t i = value.length;
    while(i--)
        os<<value.numbers[i];
    return os;
}
