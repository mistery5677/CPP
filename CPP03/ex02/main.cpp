#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

void    printIndex(int part){
    std::cout << "**************************" << std::endl;
    std::cout << "******* PART " << part << " ********" << std::endl;
    std::cout << "**************************\n" << std::endl;
}

int main(){
    printIndex(1);
    ClapTrap clap;
    ClapTrap clapClone("Miguel");

    clap.attack("Tomas");
    clap.beRepaired(10);
    clap.takeDamage(10);

    std::cout << std::endl;

    clapClone.attack("Tomas");
    clapClone.beRepaired(10);
    clapClone.takeDamage(10);
    
    std::cout << std::endl;

///////////// TEST PART2 //////////////

    printIndex(2);
    ScavTrap scav;
    ScavTrap scavClone(clapClone);

    std::cout << std::endl;

    scav.attack("Tomas");
    scav.beRepaired(10);
    scav.takeDamage(10);
    scav.guardGate();
    
    std::cout << std::endl;
    
    scavClone.attack("Miguel");
    scavClone.beRepaired(30);
    scavClone.takeDamage(20);
    scavClone.guardGate();
    scavClone.guardGate();
    
    std::cout << std::endl;

///////////// TEST PART3 //////////////

    printIndex(3);
    FragTrap frag;
    FragTrap fragClone(clapClone);

    std::cout << std::endl;

    frag.attack("Tomas");
    frag.beRepaired(10);
    frag.takeDamage(10);
    frag.highFivesGuys();

    std::cout << std::endl;

    fragClone.attack("Miguel");
    fragClone.beRepaired(30);
    fragClone.takeDamage(20);
    fragClone.highFivesGuys();

    std::cout << std::endl;
}