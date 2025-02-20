#include "PhoneBook.hpp"
#include "Contact.hpp" // A inclusão vai no .cpp, não no .hpp
#include <iostream>

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

void PhoneBook::getContacts()
{
	int index = 0;
	while(index < 8 && contacts[index].getFirstName().size() > 0)
	{
		std::cout << index + 1 << " | ";
		std::cout << contacts[index].getFirstName() << " | ";
		std::cout << contacts[index].getLastName() << " | ";
		std::cout << contacts[index].getNickName() << std::endl;
		index++;
	}
}