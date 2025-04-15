/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miafonso <miafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 10:56:50 by miafonso          #+#    #+#             */
/*   Updated: 2025/04/15 10:56:50 by miafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../include/WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){
    _type = "WrongAnimal";
    std::cout << "WrongAnimal default constructor" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type){
    _type = type;
    std::cout << "WrongAnimal constructor with type: " << type << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy){
    this->_type = copy._type;
    std::cout << "WrongAnimal --> _type " << _type << " copying information" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &src){
    this->_type = src._type;
    std::cout << "WrongAnimal --> _type " << _type << " its overloading the = operator" << std::endl;
    return *this;
}

WrongAnimal::~WrongAnimal(){
    std::cout << "WrongAnimal " << _type << " got destroyed" << std::endl;
}

void WrongAnimal::makeSound() const{
    std::cout << "WrongAnimal --> You have to specify which WrongAnimal you want to make the sound" << std::endl;
}

std::string WrongAnimal::getType() const{
    return _type;
}