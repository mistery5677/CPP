/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 23:55:18 by marvin            #+#    #+#             */
/*   Updated: 2025/03/31 23:56:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// bool bsp(Point const a, Point const b, Point const c, Point const point)
// {
//     // Produto vetorial para determinar a posição do ponto em relação às arestas do triângulo
//     Fixed area1 = (point.getX() - a.getX()) * (b.getY() - a.getY()) - (b.getX() - a.getX()) * (point.getY() - a.getY());
//     Fixed area2 = (point.getX() - b.getX()) * (c.getY() - b.getY()) - (c.getX() - b.getX()) * (point.getY() - b.getY());
//     Fixed area3 = (point.getX() - c.getX()) * (a.getY() - c.getY()) - (a.getX() - c.getX()) * (point.getY() - c.getY());

//     // O ponto está dentro do triângulo se todos os produtos vetoriais forem positivos ou todos forem negativos
//     return (area1 > 0 && area2 > 0 && area3 > 0) || (area1 < 0 && area2 < 0 && area3 < 0);
// }

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