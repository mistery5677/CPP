#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main()
{
    int N = 1;
    Zombie *zombiehorde = zombieHorde(N, "Miguel");

    for (int i = 0; i < N; i++)
        zombiehorde[i].announce();
    delete[] zombiehorde;
    return 0;
}