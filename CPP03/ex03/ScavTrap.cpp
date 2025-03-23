#include <iostream>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
    :ClapTrap(){
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    this->_guardMode = false;
    std::cout << "ScavTrap created with default constructor" << std::endl;
}

ScavTrap::ScavTrap(ClapTrap clapTrap)
    :ClapTrap(clapTrap){
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    this->_guardMode = false;
    std::cout << "ScavTrap created with clapTrap constructor" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy): ClapTrap(copy){
	std::cout << "ScavTrap Copy Constructor called" << std::endl;
	*this = copy;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name){
    this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
    this->_guardMode = false;
	std::cout << "ScavTrap Constructor with name " << this->_name << " called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &src){
    std::cout << "ScavTrap Assignation operator called" << std::endl;
	this->_name = src._name;
	this->_hitPoints = src._hitPoints;
	this->_energyPoints = src._energyPoints;
	this->_attackDamage = src._attackDamage;
    this->_guardMode = false;
	return *this;
}

ScavTrap::~ScavTrap(){
    std::cout << "Scav " << _name << " got destroyed" << std::endl;
}

void    ScavTrap::attack(const std::string& target){
    if (_energyPoints > 0) {
        std::cout << "ScavTrap " << _name << " attacks " << target << " causing " << _attackDamage << " points of damage!" << std::endl;
        _energyPoints--;
    }
    else
        std::cout << "ScavTrap " << _name << " don't have enough energy to attack!" << std::endl;
}

void    ScavTrap::guardGate(){
    if (!_guardMode){
        std::cout << this->_name << ": Guard mode ON" << std::endl;
        _guardMode = true;
    }
    else{
        std::cout << this->_name << ": Guard mode OFF" << std::endl;
        _guardMode = false;
    }
}