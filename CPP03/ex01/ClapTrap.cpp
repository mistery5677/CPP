/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miafonso <miafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 12:30:08 by miafonso          #+#    #+#             */
/*   Updated: 2025/04/04 18:44:30 by miafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("Default"),
    _hitPoints(10),
    _energyPoints(10),
    _attackDamage(0){
    std::cout << "ClapTrap " << _name << " is born!" << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name),
    _hitPoints(10),
    _energyPoints(10),
    _attackDamage(0){
    std::cout << "ClapTrap " << _name << " is born!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy){
	std::cout << "ClapTrap Copy Constructor called" << std::endl;
	*this = copy;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &src){
	std::cout << "ClapTrap Assignation operator called" << std::endl;
	this->_name = src._name;
	this->_hitPoints = src._hitPoints;
	this->_energyPoints = src._energyPoints;
	this->_attackDamage = src._attackDamage;
	return *this;
}

ClapTrap::~ClapTrap(){
    std::cout << "ClapTrap " << _name << " got destroyed" << std::endl;
}

void    ClapTrap::attack(const std::string& target){
    if (_hitPoints <= 0){
        std::cout << "ClapTrap " << _name << " is dead 💀💀" << std::endl;
    }
    else if (_energyPoints > 0){
        std::cout << "ClapTrap " << _name << " attacks " << target << " causing " << _attackDamage << " points of damage!" << std::endl;
        _energyPoints--;
    }
    else
        std::cout << "ClapTrap " << _name << " don't have enough energy to attack!" << std::endl;
}

void    ClapTrap::takeDamage(unsigned int amount){
    if (_hitPoints <= 0){
        std::cout << "ClapTrap " << _name << " is dead 💀💀" << std::endl;
    }
    else {
        std::cout << "ClapTrap " << _name << " took " << amount << " damage" << std::endl;
        _hitPoints -= amount;
    }
}

void    ClapTrap::beRepaired(unsigned int amount){
    if (_hitPoints <= 0){
        std::cout << "ClapTrap " << _name << " is dead 💀💀" << std::endl;
    }
    else if (_energyPoints > 0){
        std::cout << "ClapTrap " << _name << " got " << amount << " repair points" << std::endl;
        _energyPoints--;
    }
    else
        std::cout << "ClapTrap " << _name << " don't have enough energy to attack!" << std::endl;
}