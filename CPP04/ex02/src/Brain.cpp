#include <string>
#include <iostream>
#include "../include/Brain.hpp"

Brain::Brain() {
    _ideas = new std::string[100];
    _ideas[0] = "hello world";
    _ideas[10] = "42 lisboa";
    std::cout << "Brain default constructor" << std::endl;
}

Brain::Brain(const Brain &copy){
    std::cout << "Brain -->" << " coppyng information" << std::endl;
    this->_ideas = copy._ideas;
}

Brain& Brain::operator=(const Brain &src){
    std::cout << "Brain -->" << " its overloading the = operator" << std::endl;
    this->_ideas = src._ideas;
    return *this;
}

Brain::~Brain(){
    delete[] _ideas;
    std::cout << "Brain got destroyed" << std::endl;
}
