#include "../include/Character.hpp"
#include <iostream>
#include <string>

Character::Character(): _name("Default"){
    std::cout << "Character default constructor called" << std::endl;
}

Character::Character(std::string name): _name(name){
    std::cout << "Character default constructor called" << std::endl;
}

Character::Character(const Character& copy){
    std::cout << "Character copy constructor called" << std::endl;
    *this = copy;
}

Character& Character::operator=(const Character& src){
    std::cout << "Character equal operator called" << std::endl;
    if (this != &src) { // sempre fazer essa verificação
        this->_name = src._name;

        for (int i = 0; i < 4; ++i) {
            if (this->_inventory[i])
                delete this->_inventory[i];

            if (src._inventory[i])
                this->_inventory[i] = src._inventory[i]->clone();
            else
                this->_inventory[i] = NULL;
        }
    }
    return *this;
}

Character::~Character(){
    std::cout << "Character destructor" << std::endl;
}

std::string const & Character::getName() const {
    return _name;
}

void Character::equip(AMateria* m){
    for (int i = 0; i < 4; i++){
        if (_inventory[i] == NULL){
            std::cout << "Equiped: " << m->getType() << std::endl;
            _inventory[i] = m;
            return ;
        }
    }
    std::cout << "Inventory Full" << std::endl;
}

void Character::unequip(int idx){
    if (idx < 0 || idx > 3)
        std::cout << "Type a valid idx, from 0 - 3" << std::endl;
    else {
        if (_inventory[idx] != NULL){
            std::cout << "Unequiping the materia number " << idx << " type: " << _inventory[idx]->getType() << std::endl;
        }
        else
            std::cout << "Space empty, please equip AMateria" << std::endl;
    }
}
void Character::use(int idx, ICharacter& target){
    if (idx < 0 || idx > 3)
        std::cout << "Type a valid idx to use, from 0 - 3" << std::endl;
    else {
        if (_inventory[idx] != NULL){
            std::cout << _name << " used " << _inventory[idx]->getType() << " in " << target.getName() << std::endl;
        }
        else
            std::cout << "Space empty, please equip AMateria" << std::endl;
    }
}