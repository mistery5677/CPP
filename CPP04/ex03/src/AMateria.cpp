#include "../include/AMateria.hpp"
#include <iostream>

AMateria::AMateria(): _type("AMateria"){
    // std::cout << "AMateria default constructor" << std::endl;
}

AMateria::AMateria(std::string const & type): _type(type){
    // std::cout << "AMateria constructor the type: " << type << std::endl;
}

AMateria::AMateria(const AMateria &copy){
    this->_type = copy._type;
    // std::cout << "AMateria --> _type " << _type << " coppyng information" << std::endl;
}

AMateria& AMateria::operator=(const AMateria &src){
    this->_type = src._type;
    // std::cout << "AMateria --> _type " << _type << " its overloading the = operator" << std::endl;
    return *this;
}

std::string const& AMateria::getType() const {
    return _type;
}

void AMateria::use(ICharacter& target) {
    if (this->_type == "ice")
        std::cout << "* shots an ice bolt at " << target.getName() << " *" << std::endl;
    else
        std::cout << "* heals " << target.getName() << " wounds *" << std::endl;
    // std::cout << "AMateria base use called" << std::endl;
}

AMateria::~AMateria(){
    // std::cout << "AMateria " << _type << " got destroyed" << std::endl;
}