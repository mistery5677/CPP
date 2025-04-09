#include "../include/MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource(){
    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
    std::cout << "MateriaSource default constructor" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& copy){
    std::cout << "MateriaSource copy constructor called" << std::endl;
    for(int i = 0; i < 4; i++)
	{
		if ((copy._inventory)[i])
			(this->_inventory)[i] = (copy._inventory[i])->clone();
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& src){
    std::cout << "MateriaSource equal operator called" << std::endl;
    if (this != &src) {
        for (int i = 0; i < 4; ++i) {
            if (this->_inventory[i]){
                delete this->_inventory[i];
                this->_inventory[i] = NULL;
            }

            if (src._inventory[i])
                this->_inventory[i] = src._inventory[i]->clone();
            else
                this->_inventory[i] = NULL;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource(){
    std::cout << "MateriaSource destructor" << std::endl;
    for (int i = 0; i < 4; i++)
        if (_inventory[i] != NULL)
            delete _inventory[i];
}

void    MateriaSource::learnMateria(AMateria* materia){
    for (int i = 0; i < 4; i++) {
        if (_inventory[i] != NULL){
            std::cout << "Learned a new materia: " << materia->getType() << std::endl;
            _inventory[i] = materia;
        }
    }
    std::cout << "Too much knowledge" << std::endl;
}

AMateria*   MateriaSource::createMateria(std::string const & type){
    for (int i = 0; i < 4; i++)
        if (_inventory[i]->getType() == type){
            std::cout << "Creating a new materia with type: " << type << std::endl;
            return _inventory[i]->clone();
        }
    std::cout << "Unkown type, please add it to the materia source" << std::endl;
    return NULL;
}