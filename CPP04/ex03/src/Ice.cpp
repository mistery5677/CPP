#include "../include/Ice.hpp"
#include <iostream>

Ice::Ice(): AMateria("ice"){
    // std::cout << "Ice default constructor" << std::endl;
}

Ice::Ice(std::string type){
    _type = type;
    // std::cout << "Ice constructor the type: " << type << std::endl;
}

Ice::Ice(const Ice &copy): AMateria(){
    // std::cout << "Ice --> _type " << _type << " copying information" << std::endl;
    this->_type = copy._type;
}

Ice& Ice::operator=(const Ice &src){
    // std::cout << "Ice --> _type " << _type << " its overloading the = operator" << std::endl;
    this->_type = src._type;
    return *this;
}

Ice::~Ice(){
    // std::cout << "Ice got destroyed" << std::endl;
}

void Ice::use(ICharacter &target){
    std::cout << "* shots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria* Ice::clone() const{
    AMateria *clone = new Ice();
    std::cout << "Cloned a new Ice" << std::endl;

    return clone;
}