/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miafonso <miafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:18:48 by miafonso          #+#    #+#             */
/*   Updated: 2025/03/13 14:25:45 by miafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

int main(int argc, char **argv)
{
    if (argc == 1)
        std::cout << "Nothing to complain" << std::endl;
    else if (argc == 2)
    {
        Harl harl;  

        harl.complain(argv[1]); 
    }
    else
        std::cout << "TOO MANY THINGS TO COMPLAIN" << std::endl;
}