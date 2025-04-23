/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miafonso <miafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:28:16 by miafonso          #+#    #+#             */
/*   Updated: 2025/04/23 14:28:16 by miafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"
#include <iostream>

int getType(const std::string& literal);
void charType(const std::string& literal);
void intType(const std::string& literal);
void specialTypeNan();
void specialTypeInf(const std::string& literal);


ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter& copy){
	(void)copy;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& src){
	(void)src;
	return *this;
}

ScalarConverter::~ScalarConverter(){}

void ScalarConverter::convert(const std::string& literal){
    int type = getType(literal);
    switch (type){
        case CHAR:
            // std::cout << "Type its a Char" << std::endl;
            charType(literal);
            break;
        case INT:
            // std::cout << "Type its a Int" << std::endl;
            intType(literal);
            break;
        case FLOAT:
            // std::cout << "Type its a Float" << std::endl;
            intType(literal);
            break;
        case DOUBLE:
            // std::cout << "Type its a Double" << std::endl;
            intType(literal);
            break;
        case SPECIAL:
			if (literal == "nan" || literal == "nanf")
            	specialTypeNan();
			else
				specialTypeInf(literal);
            // std::cout << "Its a special type" << std::endl;
            break;
        default:
            std::cout << "Unknown type" << std::endl;
            break;
    }
}