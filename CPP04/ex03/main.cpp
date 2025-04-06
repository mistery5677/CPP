#include "include/AMateria.hpp"
#include "include/Ice.hpp"
#include "include/Cure.hpp"
#include "include/Character.hpp"
#include <iostream>

int main(){

    std::cout << "\n///////Creating Cure\\\\\\\\\\\n" << std::endl;

    AMateria *cure = new Cure();
    AMateria *cure_clone = cure->clone();

    std::cout << "\n///////Creating Ice\\\\\\\\\\\n" << std::endl;

    AMateria *ice = new Ice();
    AMateria *ice_clone = ice->clone();

    std::cout << "\n///////Creating Character\\\\\\\\\\\n" << std::endl;

    Character *miguel = new Character();

    miguel->equip(cure);
    miguel->equip(ice);

    std::cout << "\n///////DESTUCTION\\\\\\\\\\\n" << std::endl;

    delete cure;
    delete cure_clone;
    delete ice;
    delete ice_clone;
    delete miguel;   
}