/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miafonso <miafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 11:16:36 by miafonso          #+#    #+#             */
/*   Updated: 2025/04/15 11:16:36 by miafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
    this->_type = copy._type;
    std::cout << "Animal --> _type " << _type << " copying information" << std::endl;
}

Animal& Animal::operator=(const Animal &src){
    this->_type = src._type;
    std::cout << "Animal --> _type " << _type << " its overloading the = operator" << std::endl;
    return *this;
}

Animal::~Animal(){
    std::cout << "Animal " << _type << " got destroyed" << std::endl;
}

// Ex02 --> We remove this functions, because the class is virtual

// void Animal::makeSound() const{
//     std::cout << "Animal --> You have to specify which animal you want to make the sound" << std::endl;
// }

// std::string Animal::getType() const{
//     return _type;
// }

// std::string Animal::getIdea(int index) const{
//     (void) index;
//     return NULL;
// }