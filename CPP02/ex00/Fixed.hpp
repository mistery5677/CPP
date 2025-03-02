#pragma once

class Fixed {
private:
    int rawBits;
    static const int fractionalBits = 8; // Apenas para representar a parte fracionária

public:
    // Construtores e destrutores
    Fixed();
    Fixed(Fixed& fixed);
    Fixed& operator=(const Fixed& fixed);
    ~Fixed();
    int getRawBits() const;
    void setRawBits(int const raw);
};
