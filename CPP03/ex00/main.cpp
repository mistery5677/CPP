#include "ClapTrap.hpp"

int main(){
    ClapTrap clapTrap("miguel");

    clapTrap.attack("42");
    clapTrap.takeDamage(100);
    clapTrap.beRepaired(10);
    clapTrap.takeDamage(100);
    clapTrap.attack("42");
}