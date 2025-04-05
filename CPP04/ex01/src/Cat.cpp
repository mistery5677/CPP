#include <iostream>
#include "../include/Cat.hpp"

Cat::Cat(){
    _catType = "Cat";
    _catBrain = new Brain();
    std::cout << "Cat default constructor" << std::endl;
}

Cat::Cat(std::string type){
    _catType = type;
    _catBrain = new Brain();
    std::cout << "Cat constructor with type: " << type << std::endl;
}

Cat::Cat(const Cat &copy): Animal(copy){
    this->_catType = copy._catType;
    this->_catBrain = new Brain(*copy._catBrain);
    std::cout << "Cat --> _type " << _catType << " coppyng information" << std::endl;
}

Cat& Cat::operator=(const Cat &src){
    this->_catType = src._catType;
    
    delete this->_catBrain;
    this->_catBrain = new Brain(*src._catBrain);
    
    std::cout << "Cat --> _type " << _catType << " its overloading the = operator" << std::endl;
    return *this;
}

Cat::~Cat(){
    delete _catBrain;
    std::cout << "Cat " << _catType << " got destroyed" << std::endl;
}

void Cat::makeSound() const{
    std::cout << "Cat with the type " << _catType << " just Meow Meow" << std::endl;

}

std::string Cat::getType() const{
    return _catType;
}

std::string Cat::getIdea(int index) const{
    return _catBrain->_ideas[index];
}