/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miafonso <miafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 14:26:00 by miafonso          #+#    #+#             */
/*   Updated: 2025/04/04 14:26:00 by miafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"

FragTrap::FragTrap()
    :ClapTrap(){
        this->_hitPoints = 100;
        this->_energyPoints = 100;
        this->_attackDamage = 30;

        std::cout << "FragTrap created with default constructor" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name){
    this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap Constructor with name " << this->_name << " called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy): ClapTrap(copy){
    std::cout << "FragTrap Copy Constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &src){
    std::cout << "FragTrap Assignation operator called" << std::endl;
	this->_name = src._name;
	this->_hitPoints = src._hitPoints;
	this->_energyPoints = src._energyPoints;
	this->_attackDamage = src._attackDamage;
	return *this;
}

FragTrap::~FragTrap(){
    std::cout << "FragTrap " << _name << " got destroyed!" << std::endl;
}

void    FragTrap::attack(const std::string& target){
    if (_hitPoints <= 0){
        std::cout << "FragTrap " << _name << " is dead 💀💀" << std::endl;
    }
    else if (_energyPoints > 0) {
        std::cout << "FragTrap " << _name << " attacks " << target << " causing " << _attackDamage << " points of damage!" << std::endl;
        _energyPoints--;
    }
    else
        std::cout << "FragTrap " << _name << " don't have enough energy to attack!" << std::endl;
}

void FragTrap::highFivesGuys(){
    if (_hitPoints <= 0){
        std::cout << "FragTrap " << _name << " is dead 💀💀" << std::endl;
    }
    else
        std::cout << "FragTrap " << _name << " want to give an high five!" << std::endl;   
}