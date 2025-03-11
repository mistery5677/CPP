#include <iostream>
#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(): value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& fixed)
{
    std::cout << "Copy constructor called" << std::endl;
    value = fixed.value; // A criar uma copia dos bits raw
    std::cout << "Copy assignment operator called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& fixed)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &fixed) 
    {
        value = fixed.value;
    }
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;
    return value;
}

void Fixed::setRawBits(int const raw)
{
    value = raw;
}

///////////// PART 2 /////////////

Fixed::Fixed(const int value): value(value << fractionalBits)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float floatValue): value(roundf(floatValue * (1 << fractionalBits)))
{
    std::cout << "Float constructor called" << std::endl;
}

float Fixed::toFloat() const
{
    return static_cast<float>(value) / (1 << fractionalBits); 
}

int Fixed::toInt() const 
{
    return value >> fractionalBits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fp) 
{
    os << fp.toFloat();
    return os;

///////////// PART 3 /////////////
}