#include "ClapTrap.hpp"

int main()
{
    ClapTrap clapTrap("miguel");

    clapTrap.attack("42");
    clapTrap.beRepaired(10);
    clapTrap.takeDamage(10);
}