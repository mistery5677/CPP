#pragma once
#include "Contact.hpp"

class PhoneBook
{
private:
	class Contact contacts[8];
public:
	PhoneBook();
	void addContact();
	void getContacts();
};
