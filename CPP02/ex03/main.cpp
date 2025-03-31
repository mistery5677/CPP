/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 23:55:38 by marvin            #+#    #+#             */
/*   Updated: 2025/03/31 23:55:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>
#include <limits>

bool bsp( Point const a, Point const b, Point const c, Point const point);

void testPointInTriangle(const Point& a, const Point& b, const Point& c, const Point& point, bool expected)
{
    std::cout << "The point ( x = " << point.getX() << "\ty = " << point.getY() << " ) is inside the triangle:\n"
              << "\ta ( x = " << a.getX() << "\ty = " << a.getY() << " )\n"
              << "\tb ( x = " << b.getX() << "\ty = " << b.getY() << " )\n"
              << "\tc ( x = " << c.getX() << "\ty = " << c.getY() << " )\n";

    bool result = bsp(a, b, c, point);

    std::cout << "Expected: " << (expected ? "\033[32mTRUE\033[0m" : "\033[31mFALSE\033[0m") << "\n";
    std::cout << "Result  : " << (result ? "\033[32mTRUE\033[0m" : "\033[31mFALSE\033[0m") << "\n\n";

    if (result == expected)
        std::cout << "\033[32m✔ Test Passed!\033[0m\n";
    else
        std::cout << "\033[31m✘ Test Failed!\033[0m\n";
    
    std::cout << "-------------------------------------------------\n";
}

int main(void)
{
    std::cout << "🔹 Testing Point Inside Triangle Algorithm 🔹\n\n";

    testPointInTriangle(Point(), Point(10, 0), Point(0, 10), Point(1, 1), true);

    testPointInTriangle(Point(-1.5, -1.5), Point(2.5, 2.5), Point(-1, -2), Point(8.5, -9), false);

    return 0;
}