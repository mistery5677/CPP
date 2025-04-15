/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miafonso <miafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 11:18:22 by miafonso          #+#    #+#             */
/*   Updated: 2025/04/15 11:18:22 by miafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Character.hpp"
#include <iostream>
#include <iostream>
#include <string>

Character::Character(): _name("Default"){
    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
    _floor = NULL;
	std::cout << "Created default character" << std::endl;
}

Character::Character(std::string name): _name(name){
    // std::cout << "Character default constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
    _floor = NULL;
	std::cout << "Created " << name << " character" << std::endl;
}

Character::Character(const Character& copy): _name(copy._name), _floor(NULL) {
    for (int i = 0; i < 4; i++) {
        if (copy._inventory[i])
            this->_inventory[i] = copy._inventory[i]->clone();
        else
            this->_inventory[i] = NULL;
    }

    Floor* srcCurrent = copy._floor;
    Floor* prev = NULL;
    while (srcCurrent) {
        Floor* newNode = new Floor;
        newNode->materia = srcCurrent->materia->clone();  // deep copy
        newNode->next = NULL;

        if (!_floor)
            _floor = newNode;
        else
            prev->next = newNode;

        prev = newNode;
        srcCurrent = srcCurrent->next;
    }
}


Character& Character::operator=(const Character& src) {
    if (this != &src) {
        this->_name = src._name;

        for (int i = 0; i < 4; ++i) {
            if (this->_inventory[i]) {
                delete this->_inventory[i];
                this->_inventory[i] = NULL;
            }
            if (src._inventory[i])
                this->_inventory[i] = src._inventory[i]->clone();
            else
                this->_inventory[i] = NULL;
        }

        Floor* current = this->_floor;
        while (current != NULL) {
            Floor* next = current->next;
            delete current->materia;
            delete current;
            current = next;
        }
        this->_floor = NULL;

        Floor* srcCurrent = src._floor;
        Floor* prev = NULL;
        while (srcCurrent) {
            Floor* newNode = new Floor;
            newNode->materia = srcCurrent->materia->clone(); // deep copy!
            newNode->next = NULL;

            if (!this->_floor)
                this->_floor = newNode;
            else
                prev->next = newNode;

            prev = newNode;
            srcCurrent = srcCurrent->next;
        }
    }
    return *this;
}


Character::~Character(){
    // std::cout << "Character destructor" << std::endl;
    for (int i = 0; i < 4; i++){
        if (_inventory[i] != NULL){
            delete _inventory[i];
        }
    }
    
    Floor* current;
    if (this->_floor == NULL)
    current = NULL;
    else
        current = this->_floor;
    while (current != NULL) {
        delete current->materia;
        Floor* next = current->next;
        delete current;
        current = next;
    }
}

std::string const & Character::getName() const {
    return _name;
}

void Character::equip(AMateria* m){
    if (!m){
        std::cout << "Null materia, something is wrong" << std::endl;
        return ;
    }
    for (int x = 0; x < 4; x++){
        if (_inventory[x] != NULL && m == _inventory[x]){
            std::cout << "That materia is already equiped in space: " << x << std::endl;
            return ;
        }
    }
    for (int i = 0; i < 4; i++){
        if (_inventory[i] == NULL){
            _inventory[i] = m;
            std::cout << "Equiped: " << m->getType() << std::endl;
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
            Floor* node = new Floor;
            node->materia = _inventory[idx];
            node->next = _floor;
            _floor = node;
            std::cout << "Unequiping the materia number " << idx << " type: " << _inventory[idx]->getType() << std::endl;
            _inventory[idx] = NULL;
        }
        else
            std::cout << "Space empty, please equip AMateria" << std::endl;
    }
}

void Character::use(int idx, ICharacter& target){
    if (idx < 0 || idx > 3)
        std::cout << "Type a valid idx to use, from 0 - 3" << std::endl;
    else if (_inventory[idx] == NULL)
        std::cout << "Space empty, please equip AMateria" << std::endl;
    else {
        this->_inventory[idx]->use(target);
    }
}

void Character::checkInventory(){
    std::cout << "\nChecking Inventory of " << _name << std::endl;

    for (int i = 0; i < 4; i++)
        if (_inventory[i] != NULL)
            std::cout << _name << " inventory[" << i << "] has " << _inventory[i]->getType() << std::endl;

    std::cout << std::endl;
}