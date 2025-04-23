/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miafonso <miafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:28:19 by miafonso          #+#    #+#             */
/*   Updated: 2025/04/23 14:28:19 by miafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ScalarConverter.hpp"
#include <string>
#include <iostream>
#include <cstdlib>

bool isInt(const std::string& literal);

void checkOriginalInt(const std::string literal, float flResult){
    std::cout << "\033[1;31m";
    std::cout << "\n *******COMPARING ORIGINAL*******" << std::endl;
    std::cout << "\033[1;0m";

    int itResult = (int)flResult;
    char chResult = itResult;
    double dbResult = (double)flResult;
    std::cout << "\033[1;32m";
    std::cout << "Original Char: " << chResult << std::endl;
    std::cout << "Original Int: " << itResult << std::endl;
    std::cout << "Original Float: " << flResult << std::endl;
    std::cout << "Original Double: " << dbResult << std::endl;
    std::cout << "\033[1;0m";
    (void)literal;
}

int main(int argc, char **argv){
    if (argc == 2)
        ScalarConverter::convert(argv[1]);
    else{
        std::cout << "Invalid: ./cover <type>" << std::endl;
        return 0;
    }

    float   toFloat = std::atof(argv[1]);
    if (isInt(argv[1]))
        checkOriginalInt(argv[1], toFloat);
    // TESTAR NA ESCOLA
    // float f = 12345678.12345678f;
    // double d = 12345678.12345678;
    // std::cout << d << " | " << f << std::endl;
}

//tests done: "" | h | " " | ' ' | '' | 
//              200 | 90 | -90 | 9 | -9 | -9a9 | 9a9 | 
//              - | '-' | "-" | 4,20 | -4,20 | 4,2a0 | -4,2a0 | 4, | -4, | 4.20f | -4.20f | 4.2a0 | -4.2a0 | -4.f | 4.f | 4.20fa | 4.20f9
//              nan | nanf | -inff | +inff | -inf | +inf