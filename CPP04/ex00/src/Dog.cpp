#include <iostream>
#include "../include/Dog.hpp"

Dog::Dog(){
    _dogType = "Dog";
    std::cout << "Dog default constructor" << std::endl;
}

Dog::Dog(std::string type){
    _dogType = type;
    std::cout << "Dog constructor with type: " << type << std::endl;
}

Dog::Dog(const Dog &copy): Animal(copy){
    this->_dogType = copy._dogType;
    std::cout << "Dog --> _type " << _type << " copying information" << std::endl;
}

Dog& Dog::operator=(const Dog &src){
    this->_dogType = src._dogType;
    std::cout << "Dog --> _type " << _type << " its overloading the = operator" << std::endl;
    return *this;
}

Dog::~Dog(){
    std::cout << "Dog " << _type << " got destroyed" << std::endl;
}

void Dog::makeSound() const{
    std::cout << "Dog with the type " << _dogType << " just Ouff Ouff" << std::endl;
}

std::string Dog::getType() const{
    return _dogType;
}