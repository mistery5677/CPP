#pragma once
#include <string>
#include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap{
    private:
        bool    _guardMode;
    public:
        ScavTrap();
        ScavTrap(ClapTrap clapTrap);
        ScavTrap(const ScavTrap &copy);
        ScavTrap(std::string name);
        ~ScavTrap();
        ScavTrap& operator=(const ScavTrap &other);

        void    attack(const std::string& target);
        void    guardGate();
};