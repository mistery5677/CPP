/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miafonso <miafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 13:11:09 by miafonso          #+#    #+#             */
/*   Updated: 2025/03/13 13:50:33 by miafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main()
{
    std::string brain = "HI THIS IS BRAIN";
    std::string *stringPTR = &brain;
    std::string &stringREF = brain;

    std::cout << "Memory address string: " << &brain
            << "\nMemory address string_ptr: " << stringPTR
            << "\nMemory address string_ref: " << &stringREF << std::endl;

    std::cout << "Value string: " << brain
        << "\nValue string_ptr: " << *stringPTR
        << "\nValue string_ref: " << stringREF << std::endl;
}