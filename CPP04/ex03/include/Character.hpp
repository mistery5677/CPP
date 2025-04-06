#pragma once
#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <string>

class Character: public ICharacter{
    private:
        std::string _name;
        AMateria    *_inventory[4];
    public:
        Character();
        Character(std::string name);
        Character(const Character& copy);
        Character &operator=(const Character& copy);
        ~Character();

        std::string const & getName() const;
        void        equip(AMateria* m);
        void        unequip(int idx);
        void        use(int idx, ICharacter& target);
};