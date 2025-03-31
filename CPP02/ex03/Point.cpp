/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 23:55:47 by marvin            #+#    #+#             */
/*   Updated: 2025/03/31 23:55:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

Point::Point(): x(0), y(0)
{
}

Point::Point(const float x, const float y) : x(x), y(y)
{
}

Point& Point::operator=(const Point& dup)
{
	(void)dup;
	return *this;
}

Point::Point(const Point& other) : x(other.x), y(other.y) {}


Point::~Point()
{
}
float Point::getX() const
{
    return x.toFloat();
}


float Point::getY() const
{
    return y.toFloat();
}