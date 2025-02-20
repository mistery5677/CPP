#include <iostream>
#include <cstdlib>
#include "Contact.hpp"
#include "PhoneBook.hpp"

int main()
{
	PhoneBook phonebook;

	std::string input;
	while (1)
	{
		std::cout << "Type the command (ADD/SEARCH/EXIT): ";
		std::cin >> input;
		if (input == "ADD")
        {
			phonebook.addContact();
        }
        else if (input == "SEARCH")
        {
            phonebook.getContacts();
        }
		else if (input == "EXIT")
			exit(1);
	}
	return 0;
}