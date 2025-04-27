/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mistery576 <mistery576@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 21:46:23 by mistery576        #+#    #+#             */
/*   Updated: 2025/04/22 16:47:21 by mistery576       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/whatever.hpp"


int main(){
    std::cout << "\033[1;31m";
    std::cout << "*******TESTING SWAP*******\n" << std::endl;
    std::cout << "\033[1;0m";

    int x = 10;
    int y = 20;
    std::cout << "X value: " << x << " | Y value: " << y << std::endl;

    ::swap(x, y);
    std::cout << "\033[1;32m";
    std::cout << "Swaped values" << std::endl;
    std::cout << "\033[1;0m";

    std::cout << "X value: " << x << " | Y value: " << y << std::endl;

    std::cout << "\033[1;31m";
    std::cout << "\n*******TESTING MIN*******\n" << std::endl;
    std::cout << "\033[1;0m";

    int min = 0;
    int max = 10;
    
    int &equal = ::min(min, max);
    
    std::cout << &min << " | " << &equal << std::endl;
    
    std::cout << "\033[1;33m";
    std::cout << "Same values" << std::endl;
    std::cout << "\033[1;0m";
    int min2 = 0;
    int &equal2 = ::min(min2, equal);

    std::cout << &min << " | " << &equal2 << std::endl;

    std::cout << "\033[1;31m";
    std::cout << "\n*******TESTING MAX*******\n" << std::endl;
    std::cout << "\033[1;0m";

    int &equal3 = ::max(min, max);
    
    std::cout << &max << " | " << &equal3 << std::endl;
    
    std::cout << "\033[1;33m";
    std::cout << "Same values" << std::endl;
    std::cout << "\033[1;0m";
    int max2 = 10;
    int &equal4 = ::max(max2, equal3);

    std::cout << &max << " | " << &equal4 << std::endl;

    std::cout << "\033[1;31m";
    std::cout << "\n*******SUBJECT TESTS*******\n" << std::endl;
    std::cout << "\033[1;0m";

    int a = 2;
    int b = 3;
    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
}