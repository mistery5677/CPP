#pragma once
#include "ScavTrap.hpp"

class FragTrap: public ClapTrap{
    private:

    public:
        FragTrap();
        FragTrap(ClapTrap clapTrap);
        FragTrap(const FragTrap &copy);
        FragTrap(std::string name);
        ~FragTrap();
        FragTrap& operator=(const FragTrap &src);

        void    highFivesGuys(void);
};