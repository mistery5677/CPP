#include <iostream>
#include "../include/Cat.hpp"

Cat::Cat(){
    _type = "Cat";
    _brain = new Brain();
    std::cout << "Cat default constructor" << std::endl;
}

Cat::Cat(std::string type){
    _type = type;
    _brain = new Brain();
    std::cout << "Cat constructor with type: " << type << std::endl;
}

Cat::Cat(const Cat &copy): Animal(copy){
    this->_type = copy._type;
    this->_brain = new Brain(*copy._brain);
    std::cout << "Cat --> _type " << _type << " coppyng information" << std::endl;
}

Cat& Cat::operator=(const Cat &src){
    this->_type = src._type;
    
    delete this->_brain;
    this->_brain = new Brain(*src._brain);
    
    std::cout << "Cat --> _type " << _type << " its overloading the = operator" << std::endl;
    return *this;
}

Cat::~Cat(){
    delete _brain;
    std::cout << "Cat " << _type << " got destroyed" << std::endl;
}

void Cat::makeSound() const{
    std::cout << "Meow Meow" << std::endl;
}

std::string Cat::getType() const{
    return _type;
}

std::string Cat::getIdea(int index) const{
    return _brain->_ideas[index];
}