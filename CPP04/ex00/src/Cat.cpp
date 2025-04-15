/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miafonso <miafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 10:56:45 by miafonso          #+#    #+#             */
/*   Updated: 2025/04/15 10:56:45 by miafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../include/Cat.hpp"

Cat::Cat(){
    _catType = "Cat";
    std::cout << "Cat default constructor" << std::endl;
}

Cat::Cat(std::string type){
    _catType = type;
    std::cout << "Cat constructor with type: " << type << std::endl;
}

Cat::Cat(const Cat &copy): Animal(copy){
    this->_catType = copy._catType;
    std::cout << "Cat --> _type " << _type << " copying information" << std::endl;
}

Cat& Cat::operator=(const Cat &src){
    this->_catType = src._catType;
    std::cout << "Cat --> _type " << _type << " its overloading the = operator" << std::endl;
    return *this;
}

Cat::~Cat(){
    std::cout << "Cat " << _catType << " got destroyed" << std::endl;
}

void Cat::makeSound() const{
    std::cout << "Cat with the type " << _catType << " just Meow Meow" << std::endl;
}

std::string Cat::getType() const{
    return _catType;
}