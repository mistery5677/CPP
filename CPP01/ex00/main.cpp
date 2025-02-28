#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main()
{
    Zombie *zombie_heaped = newZombie("");
    randomChump("");

    zombie_heaped->announce();
    delete zombie_heaped;
}