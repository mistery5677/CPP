#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name)
    :name(name)
{
}

Zombie::~Zombie()
{
    std::cout << name << ": Got killed" << std::endl;
}

void Zombie::announce(void)
{
    std::cout << name << ": : BraiiiiiiinnnzzzZ..." << std::endl;
}