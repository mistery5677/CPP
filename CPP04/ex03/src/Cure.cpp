/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miafonso <miafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 11:18:24 by miafonso          #+#    #+#             */
/*   Updated: 2025/04/15 11:18:24 by miafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cure.hpp"
#include <iostream>

Cure::Cure(): AMateria("cure"){
    // std::cout << "Cure default constructor" << std::endl;
}

Cure::Cure(std::string type){
    _type = type;
    // std::cout << "Cure constructor the type: " << type << std::endl;
}

Cure::Cure(const Cure &copy): AMateria(){
    // std::cout << "Cure --> _type " << _type << " copying information" << std::endl;
    this->_type = copy._type;
}

Cure& Cure::operator=(const Cure &src){
    // std::cout << "Cure --> _type " << _type << " its overloading the = operator" << std::endl;
    this->_type = src._type;
    return *this;
}

Cure::~Cure(){
    // std::cout << "Cure got destroyed" << std::endl;
}

void Cure::use(ICharacter &target){
    std::cout << "* heals " << target.getName() << " wounds *" << std::endl;
}

AMateria* Cure::clone() const{
    AMateria *clone = new Cure();
    std::cout << "Cloned a new Cure" << std::endl;

    return clone;
}
