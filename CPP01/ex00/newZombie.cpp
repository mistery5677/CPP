#include "Zombie.hpp"
#include <cstdlib>

Zombie* newZombie(std::string name)
{
    Zombie *zombie = new Zombie(name);
    return zombie;
}