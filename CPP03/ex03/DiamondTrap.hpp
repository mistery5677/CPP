#pragma once
#include <string>
#include "FragTrap.hpp"

class DiamondTrap:public ScavTrap, public FragTrap{
    private:
        std::string _name;
    public:
        DiamondTrap();
        DiamondTrap(ClapTrap clapTrap);
        DiamondTrap(const DiamondTrap &copy);
        ~DiamondTrap();
        DiamondTrap& operator=(const DiamondTrap &src);

        ScavTrap::attack(const std::string& target);
};