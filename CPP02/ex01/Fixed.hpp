#pragma once

class Fixed {
private:
    int value;
    static const int fractionalBits = 8; // Apenas para representar a parte fracionária

public:
    // Construtores e destrutores
    Fixed(const int number);
    Fixed(Fixed& fixed);
    Fixed(const float floatNumber);
    Fixed& operator=(const Fixed& fixed);
    ~Fixed();
    int getRawBits() const;
    void setRawBits(int const raw);
};
