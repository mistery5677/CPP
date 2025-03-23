#include <iostream>
#include "FragTrap.hpp"

FragTrap::FragTrap()
    :ClapTrap(){
        this->_hitPoints = 100;
        this->_energyPoints = 100;
        this->_attackDamage = 30;

        std::cout << "FragTrap created with default constructor" << std::endl;
}

FragTrap::FragTrap(ClapTrap clapTrap)
    :ClapTrap(clapTrap){
        this->_hitPoints = 100;
        this->_energyPoints = 100;
        this->_attackDamage = 30;
        std::cout << "FragTrap created with ClapTrap name constructor" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy): ClapTrap(copy){
    std::cout << "FragTrap Copy Constructor called" << std::endl;
	*this = copy;
}

FragTrap::FragTrap(std::string name): ClapTrap(name){
    this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap Constructor with name " << this->_name << " called" << std::endl;
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

void FragTrap::highFivesGuys(){
    std::cout << "FragTrap " << _name << " want to give an high five!" << std::endl;   
}