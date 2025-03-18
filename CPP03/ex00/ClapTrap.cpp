#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name) {
    _hitPoints = 10;
    _energyPoints = 10;
    _attackDamage = 0;
    std::cout << "ClapTrap " << _name << " is born!" << std::endl;
}

ClapTrap::~ClapTrap(){
    std::cout << "ClapTrap " << _name << " got destroyed" << std::endl;
}

void    ClapTrap::attack(const std::string& target){
    std::cout << "ClapTrap " << _name << " attacks " << target << " causing " << _attackDamage << " points of damage!" << std::endl;
}

void    ClapTrap::takeDamage(unsigned int amount){
    std::cout << "ClapTrap " << _name << " took " << amount << " damage" << std::endl;
}

void    ClapTrap::beRepaired(unsigned int amount){
    std::cout << "ClapTrap " << _name << " got " << amount << " repair points" << std::endl;
}