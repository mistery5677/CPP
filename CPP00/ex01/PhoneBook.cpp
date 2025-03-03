/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miafonso <miafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:24:42 by miafonso          #+#    #+#             */
/*   Updated: 2025/03/03 13:24:09 by miafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp" // A inclusão vai no .cpp, não no .hpp
#include <iostream>
#include <iomanip>
#include <limits>

PhoneBook::PhoneBook()
{
}

void PhoneBook::addContact()
{
	static int index;
	int pos = index % 8;

	if (contacts[pos].setContact())
		index++;
	else
		std::cout << "Contact not added to contacts" << std::endl;
}

void PhoneBook::showContact(int index, Contact contact)
{
    std::cout << std::setw(1) << index + 1 << " | ";

    // Format and truncate fields if necessary
    std::cout << std::setw(10) << (contact.getFirstName().size() > 10 
        ? contact.getFirstName().substr(0, 9) + "." : contact.getFirstName()) << " | ";

    std::cout << std::setw(10) << (contact.getLastName().size() > 10 
        ? contact.getLastName().substr(0, 9) + "." : contact.getLastName()) << " | ";

    std::cout << std::setw(10) << (contact.getNickName().size() > 10 
        ? contact.getNickName().substr(0, 9) + "." : contact.getNickName()) << std::endl;
}

void PhoneBook::findContact()
{
	int index;

	if (contacts[0].getFirstName().empty())
	{
		std::cout << "Empty contacts list" << std::endl;
		return ;
	}
	std::cin >> index;
	if (index > 8 || index < 1 || contacts[index - 1].getFirstName().empty())
	{
		std::cout << "Invalid index" << std::endl;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return ;
	}
	std::cout << "First Name: " << contacts[index - 1].getFirstName() << std::endl;
	std::cout << "Last Name: " << contacts[index - 1].getLastName() << std::endl;
	std::cout << "Nick Name: " << contacts[index - 1].getNickName() << std::endl;
	std::cout << "Phone number: " << contacts[index - 1].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << contacts[index - 1].getDarkestSecret() << std::endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

}

void PhoneBook::getContacts()
{
	int index = 0;
	while(index < 8 && contacts[index].getFirstName().size() > 0)
	{
		showContact(index, contacts[index]);
		index++;
	}
	std::cout << "Type the index you want to access: ";
	findContact();
}