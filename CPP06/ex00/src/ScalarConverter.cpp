#include "../include/ScalarConverter.hpp"
#include <iostream>

int getType(const std::string& literal);
void charType(const std::string& literal);
void intType(const std::string& literal);
void specialType();

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
            // std::cout << "Its a special type" << std::endl;
            specialType();
            break;
        default:
            std::cout << "Unknown type" << std::endl;
            break;
    }
}