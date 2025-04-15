/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miafonso <miafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 11:14:34 by miafonso          #+#    #+#             */
/*   Updated: 2025/04/15 11:14:34 by miafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../include/WrongCat.hpp"

WrongCat::WrongCat(){
    _type = "WrongCat";
    std::cout << "WrongCat default constructor" << std::endl;
}

WrongCat::WrongCat(std::string type){
    _type = type;
    std::cout << "WrongCat constructor with type: " << type << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy): WrongAnimal(copy){
    this->_type = copy._type;
    std::cout << "WrongCat --> _type " << _type << " copying information" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &src){
    this->_type = src._type;
    std::cout << "WrongCat --> _type " << _type << " its overloading the = operator" << std::endl;
    return *this;
}

WrongCat::~WrongCat(){
    std::cout << "WrongCat " << _type << " got destroyed" << std::endl;
}

void WrongCat::makeSound() const{
    std::cout << "Wrong Meow Meow" << std::endl;
}

std::string WrongCat::getType() const{
    return _type;
}