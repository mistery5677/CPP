#include "../include/Cure.hpp"
#include <iostream>

Cure::Cure(): _type("Default"){
    std::cout << "Cure default constructor" << std::endl;
}

Cure::Cure(std::string type){
    _type = type;
    std::cout << "Cure constructor the type: " << type << std::endl;
}

Cure::Cure(const Cure &copy){
    std::cout << "Cure --> _type " << _type << " coppyng information" << std::endl;
    this->_type = copy._type;
}

Cure& Cure::operator=(const Cure &src){
    std::cout << "Cure --> _type " << _type << " its overloading the = operator" << std::endl;
    this->_type = src._type;
    return *this;
}

Cure::~Cure(){
    std::cout << "Cure " << _type << " got destroyed" << std::endl;
}