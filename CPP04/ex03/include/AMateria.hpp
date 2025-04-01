#pragma once
#include <string>

class AMateria {
    protected:

    public:
        AMateria(std::sting const& type);

        std::string const&  getType() const;

        virtual             AMateria* clone() const = 0;
        virtual void        use(ICharacter& target);
};