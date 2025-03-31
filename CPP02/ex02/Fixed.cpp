/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 23:54:53 by marvin            #+#    #+#             */
/*   Updated: 2025/03/31 23:54:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
    *this = fixed;
}

Fixed& Fixed::operator=(const Fixed& fixed)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &fixed) 
    {
        value = fixed.getRawBits();
    }
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
    // std::cout << "getRawBits member function called" << std::endl;
    return value;
}

void Fixed::setRawBits(int const raw)
{
    value = raw;
}

///////////// PART 2 /////////////

Fixed::Fixed(const int value): value(value << fractionalBits)
{
    //std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float floatValue): value(roundf(floatValue * (1 << fractionalBits)))
{
    //std::cout << "Float constructor called" << std::endl;
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
}
///////////// PART 3 /////////////

bool Fixed::operator>(const Fixed& other) const
{
    return this->value > other.value;
}

bool Fixed::operator<(const Fixed& other) const
{
    return this->value < other.value;
}

bool Fixed::operator>=(const Fixed& other) const
{
    return this->value >= other.value;
}

bool Fixed::operator<=(const Fixed& other) const
{
    return this->value <= other.value;
}

bool Fixed::operator==(const Fixed& other) const
{
    return this->value == other.value;
}

bool Fixed::operator!=(const Fixed& other) const
{
    return this->value != other.value;
}

Fixed& Fixed::operator++() // ++x
{
    value += 1;
    return *this;
}

Fixed Fixed::operator++(int) // x++
{
    Fixed temp = *this;
    value += 1;
    return temp;
}

Fixed& Fixed::operator--()
{
    value -= 1;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    value -= 1;
    return temp;
}

Fixed Fixed::operator+(const Fixed& other) const
{
    return (this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const
{
    return (this->toFloat() - other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const
{
    return (this->toFloat() / other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const
{
    return (this->toFloat() * other.toFloat());
}

Fixed& Fixed::min(Fixed& n1, Fixed& n2)
{
    if (n1.value < n2.value)
        return n1;
    else
        return n2;
}

const Fixed& Fixed::min(const Fixed& n1, const Fixed& n2)
{
    if (n1.value < n2.value)
        return n1;
    else
        return n2;
}

Fixed& Fixed::max(Fixed& n1, Fixed& n2)
{
    if (n1.value > n2.value)
        return n1;
    else
        return n2;
}

const Fixed& Fixed::max(const Fixed& n1, const Fixed& n2)
{
    if (n1.value > n2.value)
        return n1;
    else
        return n2;
}
