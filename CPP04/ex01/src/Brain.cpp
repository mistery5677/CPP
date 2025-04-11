#include <string>
#include <iostream>
#include <sstream>
#include "../include/Brain.hpp"

Brain::Brain() {
    _ideas = new std::string[100];
    for (int i = 0; i < 100; i++){
        std::stringstream ss;
        ss << "Idea Number: " << i;
        _ideas[i] = ss.str();
    }
    std::cout << "Brain default constructor" << std::endl;
}

Brain::Brain(const Brain &copy){
    std::cout << "Brain -->" << " copying information" << std::endl;
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
