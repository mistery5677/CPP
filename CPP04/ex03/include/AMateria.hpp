#pragma once
#include "ICharacter.hpp"
#include <string>

class ICharacter;

class AMateria {
    protected:
        std::string _type;
    public:
        AMateria();
        AMateria(const AMateria &copy);
        AMateria &operator=(const AMateria &src);
        virtual ~AMateria();

        AMateria(std::string const & type);

        std::string const&  getType() const;

        virtual AMateria*   clone() const = 0;
        virtual void        use(ICharacter& target);
};