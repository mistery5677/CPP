/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miafonso <miafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:01:01 by miafonso          #+#    #+#             */
/*   Updated: 2025/03/03 13:22:25 by miafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <limits>
#include "Contact.hpp"
#include "PhoneBook.hpp"

int main()
{
	PhoneBook phonebook;

	std::string input;
	while (1)
	{
		std::cout << "Type the command (ADD/SEARCH/EXIT): ";
		std::getline(std::cin, input);
		if (input == "ADD")
			phonebook.addContact();
        else if (input == "SEARCH")
            phonebook.getContacts();
		else if (input == "EXIT")
			exit(1);
	}
	return 0;
}