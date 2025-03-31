/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 23:55:50 by marvin            #+#    #+#             */
/*   Updated: 2025/03/31 23:55:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma  once
#include "Fixed.hpp"

class Point
{
private:
    const Fixed x;
    const Fixed y;
public:
    Point();
    Point(const float x, const float y);
    Point(const Point& other);
    Point& operator=(const Point& dup);
    ~Point();

    float getX() const;
    float getY() const;
};