#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed(const int number): value(number)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const float floatNumber): value(floatNumber)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed& fixed)
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