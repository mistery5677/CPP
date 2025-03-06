#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed(): value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& fixed)
{
    std::cout << "Copy constructor called" << std::endl;
    value = fixed.value; // A criar uma copia dos bits raw
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

Fixed::Fixed(const int value): value(value)
{
}

Fixed::Fixed(const float value): value(value)
{
}

float Fixed::toFloat()
{
    return value * 2 ^ fractionalBits; 
}

int Fixed::toInt()
{
    return value << fractionalBits;
}

std::ostream& operator<<(std::ostream& os, Fixed& fp) 
{
    os << fp.toFloat(); // Insert floating-point representation into the stream
    return os;
}