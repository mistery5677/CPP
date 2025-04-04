/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miafonso <miafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 23:55:18 by marvin            #+#    #+#             */
/*   Updated: 2025/04/04 12:00:35 by miafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed const x = point.getX();
	Fixed const y = point.getY();
	Fixed const x1 = a.getX();
	Fixed const y1 = a.getY();
	Fixed const x2 = b.getX();
	Fixed const y2 = b.getY();
	Fixed const x3 = c.getX();
	Fixed const y3 = c.getY();
	Fixed const a1 = (x - x1) * (y2 - y1) - (x2 - x1) * (y - y1);
	Fixed const a2 = (x - x2) * (y3 - y2) - (x3 - x2) * (y - y2);
	Fixed const a3 = (x - x3) * (y1 - y3) - (x1 - x3) * (y - y3);
	if ((a1 >= 0 && a2 >= 0 && a3 >= 0) || (a1 <= 0 && a2 <= 0 && a3 <= 0))
		return true;
	return false;
}

// Barycentric way