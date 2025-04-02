#include "../include/Cure.hpp"
#include <iostream>

Cure::Cure(): _type("Cure"){
    std::cout << "Cure default constructor" << std::endl;
}

Cure::Cure(std::string type){
    _type = type;
    std::cout << "Cure constructor the type: " << type << std::endl;
}

Cure::Cure(const Cure &copy): AMateria(){
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

AMateria* Cure::clone() const{
    AMateria *clone = new Cure();
    std::cout << "Cloned a new Cure" << std::endl;

    return clone;
}