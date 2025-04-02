#include "../include/AMateria.hpp"
#include <iostream>

AMateria::AMateria(): _type("AMateria"){
    std::cout << "AMateria default constructor" << std::endl;
}

AMateria::AMateria(std::string type){
    _type = type;
    std::cout << "AMateria constructor the type: " << type << std::endl;
}

AMateria::AMateria(const AMateria &copy){
    std::cout << "AMateria --> _type " << _type << " coppyng information" << std::endl;
    this->_type = copy._type;
}

AMateria& AMateria::operator=(const AMateria &src){
    std::cout << "AMateria --> _type " << _type << " its overloading the = operator" << std::endl;
    this->_type = src._type;
    return *this;
}

AMateria::~AMateria(){
    std::cout << "AMateria " << _type << " got destroyed" << std::endl;
}