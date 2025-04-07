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

    ICharacter *character = new Character();
    ICharacter *miguel = new Character("Miguel");

    std::cout << "\n///////Testing Character\\\\\\\\\\\n" << std::endl;

    character->equip(cure);
    character->equip(ice);

    character->checkInventory();

    character->unequip(0);

    character->checkInventory();

    std::cout << "\n///////Testing Miguel\\\\\\\\\\\n" << std::endl;

    miguel->equip(cure);
    miguel->equip(ice);

    miguel->checkInventory();

    miguel->unequip(0);

    miguel->checkInventory();
    miguel->equip(ice);
    miguel->equip(ice);
    miguel->equip(ice);
    miguel->equip(ice);
    miguel->equip(ice);

    miguel->checkInventory();
    miguel->unequip(0);
    miguel->unequip(0);

    miguel->checkInventory();
    miguel->use(0, *character);
    miguel->use(1, *character);

    miguel->checkInventory();

    std::cout << "\n///////DESTUCTION\\\\\\\\\\\n" << std::endl;

    delete cure;
    delete cure_clone;
    delete ice;
    delete ice_clone;
    delete miguel;
    delete character;
}