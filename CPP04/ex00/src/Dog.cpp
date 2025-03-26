#include <iostream>
#include "../include/Dog.hpp"

Dog::Dog(){
    _type = "Dog";
    std::cout << "Dog default constructor" << std::endl;
}

Dog::Dog(std::string type){
    _type = type;
    std::cout << "Dog constructor with type: " << type << std::endl;
}

Dog::Dog(const Dog &copy): Animal(copy){
    this->_type = copy._type;
    std::cout << "Dog --> _type " << _type << " coppyng information" << std::endl;
}

Dog& Dog::operator=(const Dog &src){
    this->_type = src._type;
    std::cout << "Dog --> _type " << _type << " its overloading the = operator" << std::endl;
    return *this;
}

Dog::~Dog(){
    std::cout << "Dog " << _type << " got destroyed" << std::endl;
}

void Dog::makeSound() const{
    std::cout << "Oufff Oufff" << std::endl;
}

std::string Dog::getType() const{
    return _type;
}