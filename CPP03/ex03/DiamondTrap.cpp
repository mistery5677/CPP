/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miafonso <miafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 14:27:11 by miafonso          #+#    #+#             */
/*   Updated: 2025/04/04 14:27:11 by miafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
// #include "ClapTrap.hpp"
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
    :ClapTrap("default_clap_trap"){
        this->_name = "Default";
        this->_hitPoints = FragTrap::_hitPoints;
        this->_energyPoints = ScavTrap::_energyPoints;
        this->_attackDamage = FragTrap::_attackDamage;
        std::cout << "DiamondTrap created with default constructor" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
    :ClapTrap(name + "_clap_trap"){
        this->_name = name;
        this->_hitPoints = FragTrap::_hitPoints;
        this->_energyPoints = ScavTrap::_energyPoints;
        this->_attackDamage = FragTrap::_attackDamage;
        std::cout << "DiamondTrap created with parameter constructor" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy): ClapTrap(copy._name), ScavTrap(copy._name), FragTrap(copy._name){
	std::cout << "DiamondTrap Copy Constructor called" << std::endl;
	*this = copy;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &src){
    std::cout << "DiamondTrap Assignation operator called" << std::endl;
	this->_name = src._name;
	this->_hitPoints = src._hitPoints;
	this->_energyPoints = src._energyPoints;
	this->_attackDamage = src._attackDamage;
	return *this;
}

DiamondTrap::~DiamondTrap(){
    std::cout << "DiamondTrap " << _name << " got destroyed" << std::endl;
}

void DiamondTrap::attack(const std::string& target){
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(){
    std::cout << "DiamondTrap got constructed with the " << ClapTrap::_name << " ClapTrap scraps " << _name << std::endl;
}