#include "../include/Ice.hpp"
#include <iostream>

Ice::Ice(): _type("Default"){
    std::cout << "Ice default constructor" << std::endl;
}

Ice::Ice(std::string type){
    _type = type;
    std::cout << "Ice constructor the type: " << type << std::endl;
}

Ice::Ice(const Ice &copy){
    std::cout << "Ice --> _type " << _type << " coppyng information" << std::endl;
    this->_type = copy._type;
}

Ice& Ice::operator=(const Ice &src){
    std::cout << "Ice --> _type " << _type << " its overloading the = operator" << std::endl;
    this->_type = src._type;
    return *this;
}

Ice::~Ice(){
    std::cout << "Ice " << _type << " got destroyed" << std::endl;
}