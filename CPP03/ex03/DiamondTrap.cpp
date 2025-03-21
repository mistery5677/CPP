#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
    :ClapTrap(){
        this->_hitPoints = FragTrap::_hitPoints;
        this->_energyPoints = ScavTrap::_energyPoints;
        this->_attackDamage = FragTrap::_attackDamage;
        std::cout << "DiamondTrap created with default constructor" << std::endl;
}

DiamondTrap::DiamondTrap(ClapTrap clapTrap)
    :ClapTrap(clapTrap){
        this->_hitPoints = FragTrap::_hitPoints;
        this->_energyPoints = ScavTrap::_energyPoints;
        this->_attackDamage = FragTrap::_attackDamage;
        std::cout << "DiamondTrap created with clapTrap constructor" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy): ClapTrap(){
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
    std::cout << "Scav " << _name << " got destroyed" << std::endl;
}

// void    DiamondTrap::attack(const std::string& target){
//     std::cout << "DiamondTrap " << _name << " attacks " << target << " causing " << _attackDamage << " points of damage!" << std::endl;
// }

// void    DiamondTrap::guardGate(){
//     if (!guardMode){
//         std::cout << this->_name << ": Guard mode ON" << std::endl;
//         guardMode = true;
//     }
//     else{
//         std::cout << this->_name << ": Guard mode OFF" << std::endl;
//         guardMode = false;
//     }
// }