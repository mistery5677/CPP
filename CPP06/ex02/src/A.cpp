#include "../include/A.hpp"
#include <iostream>

A::A(){
    std::cout << "Constructor A called" << std::endl;
}

A::~A(){
    std::cout << "Destructor A called" << std::endl;
}