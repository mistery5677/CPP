#pragma once
#include <ostream>

class Fixed {
private:
    int value;
    static const int fractionalBits = 8;
public:
    Fixed();
    Fixed(const Fixed& fixed);
    Fixed& operator=(const Fixed& fixed);
    ~Fixed();
    int getRawBits() const;
    void setRawBits(int const raw);

///////////// PART 2 /////////////
    Fixed(const int value);
    Fixed(const float floatValue);
    float toFloat() const;
    int toInt() const;
    friend std::ostream& operator<<(std::ostream& os, const Fixed& fp);

///////////// PART 3 /////////////
    bool operator>(const Fixed& other) const;
    bool operator<(const Fixed& other) const;
    bool operator>=(const Fixed& other) const;
    bool operator<=(const Fixed& other) const;
    bool operator==(const Fixed& other) const;
    bool operator!=(const Fixed& other) const;

    Fixed& operator++();
    Fixed operator++(int);
    Fixed& operator--();
    Fixed operator--(int);
    Fixed operator+(const Fixed& other) const;
    Fixed operator-(const Fixed& other) const;
    Fixed operator/(const Fixed& other) const;
    Fixed operator*(const Fixed& other) const;

    static Fixed& min(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static Fixed& max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);
};
