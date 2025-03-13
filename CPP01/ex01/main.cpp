/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miafonso <miafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:44:50 by miafonso          #+#    #+#             */
/*   Updated: 2025/03/13 13:10:06 by miafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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