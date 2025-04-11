#include <iostream>
#include "../include/Dog.hpp"

Dog::Dog(){
    _dogType = "Dog";
    _dogBrain = new Brain();
    std::cout << "Dog default constructor" << std::endl;
}

Dog::Dog(std::string type){
    _dogType = type;
    _dogBrain = new Brain();
    std::cout << "Dog constructor with type: " << type << std::endl;
}

Dog::Dog(const Dog &copy): Animal(copy){
    this->_dogType = copy._dogType;
    this->_dogBrain = new Brain(*copy._dogBrain);
    std::cout << "Dog --> _type " << _dogType << " copying information" << std::endl;
}

Dog& Dog::operator=(const Dog &src){
    this->_dogType = src._dogType;

    delete this->_dogBrain;
    this->_dogBrain = new Brain(*src._dogBrain);
    
    std::cout << "Dog --> _type " << _dogType << " its overloading the = operator" << std::endl;
    return *this;
}

Dog::~Dog(){
    delete _dogBrain;
    std::cout << "Dog " << _dogType << " got destroyed" << std::endl;
}

void Dog::makeSound() const{
    std::cout << "Dog with the type " << _dogType << " just Ouff Ouff" << std::endl;
}

std::string Dog::getType() const{
    return _dogType;
}

std::string Dog::getIdea(int index) const{
    return _dogBrain->_ideas[index];
}