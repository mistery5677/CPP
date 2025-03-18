#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap{
    private:
        
    public:
        ScavTrap(ClapTrap(std::string name));
        ~ScavTrap();

        void    guardGate();
};