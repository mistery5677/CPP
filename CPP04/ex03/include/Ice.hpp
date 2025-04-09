#pragma once
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <string>

class Ice: public AMateria {
    private:
        std::string _type;
    public:
        Ice();
        Ice(std::string type);
        Ice(const Ice &copy);
        Ice &operator=(const Ice &src);
        ~Ice();

        void        use(ICharacter& target);
        AMateria*   clone() const;
};