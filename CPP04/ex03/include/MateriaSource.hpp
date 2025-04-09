#pragma once
#include "IMateriaSource.hpp"
#include "AMateria.hpp"
#include <string>

class MateriaSource: public IMateriaSource {
    private:
        AMateria *_inventory[4];
    public:
        MateriaSource();
        MateriaSource(const MateriaSource& copy);
        MateriaSource &operator=(const MateriaSource& copy);
        ~MateriaSource();
        
        void        learnMateria(AMateria* materia);
        AMateria*   createMateria(std::string const & type);
};