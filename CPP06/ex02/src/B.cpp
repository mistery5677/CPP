#include "../include/B.hpp"
#include <iostream>

B::B(){
    std::cout << "Constructor B called" << std::endl;
}

B::~B(){
    std::cout << "Destructor B called" << std::endl;
}