/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miafonso <miafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:28:45 by miafonso          #+#    #+#             */
/*   Updated: 2025/03/13 14:28:46 by miafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    switch (argc)
    {
        case 1:
        {
            std::cout << "Nothing for Harl to complain" << std::endl;
            break;
        }
        case 2:
        {
            Harl harl;

            harl.complain(argv[1]);
            break;
        }
        default:
        {
            std::cout << "Many things for Harl to complain" << std::endl;
            break;
        }
    }
}