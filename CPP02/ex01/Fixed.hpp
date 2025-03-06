#pragma once

class Fixed {
private:
    int value;
    static const int fractionalBits = 8; // Apenas para representar a parte fracionária

public:
    // Construtores e destrutores
    Fixed();
    Fixed(const Fixed& fixed);
    Fixed& operator=(const Fixed& fixed);
    ~Fixed();
    int getRawBits() const;
    void setRawBits(int const raw);

///////////// PART 2 /////////////
    Fixed(const int value);
    Fixed(const float value);
    float toFloat();
    int toInt();
    friend std::ostream& operator<<(std::ostream& os, Fixed& fp);
};

