/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 14:25:45 by miafonso          #+#    #+#             */
/*   Updated: 2025/04/05 02:02:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

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
    ScavTrap scavClone("Teste");

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
    
    // std::cout << "Life " << scav.getHitPoints() << std::endl;
    
    std::cout << std::endl;
}