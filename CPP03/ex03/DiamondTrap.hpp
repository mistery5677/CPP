#pragma once
#include <string>
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
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

        void attack(const std::string& target);
};