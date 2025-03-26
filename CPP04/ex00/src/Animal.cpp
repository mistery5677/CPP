#include <string>
#include <iostream>
#include "../include/Animal.hpp"

Animal::Animal(): _type("Default"){
    std::cout << "Animal default constructor" << std::endl;
}

Animal::Animal(std::string type){
    _type = type;
    std::cout << "Animal constructor the type: " << type << std::endl;
}

Animal::Animal(const Animal &copy){
    std::cout << "Animal --> _type " << _type << " coppyng information" << std::endl;
    this->_type = copy._type;
}

Animal& Animal::operator=(const Animal &src){
    std::cout << "Animal --> _type " << _type << " its overloading the = operator" << std::endl;
    this->_type = src._type;
    return *this;
}

Animal::~Animal(){
    std::cout << "Animal " << _type << " got destroyed" << std::endl;
}

void Animal::makeSound() const{
    std::cout << "Animal --> You have to specify which animal you want to make the sound" << std::endl;
}

std::string Animal::getType() const{
    return _type;
}