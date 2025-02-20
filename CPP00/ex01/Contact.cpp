#include <iostream>
#include "Contact.hpp"

Contact::Contact()
{
}

bool Contact::check_str(std::string str)
{
	int i = 0;
	
	while (str[i])
	{
		if (std::isdigit(str[i]))
        {   
            std::cout << "Invalid input" << std::endl;
			return false;
        }
		i++;
	}
	return true;
}

bool Contact::setContact()
{
    std::string tempFirstName, tempLastName, tempNickName, tempPhoneNumber, tempDarkestSecret;

    std::cout << "First Name: ";
    std::cin >> tempFirstName;
    if (!check_str(tempFirstName))
        return false;

    std::cout << "Last Name: ";
    std::cin >> tempLastName;
    if (!check_str(tempLastName))
        return false;

    std::cout << "Nickname: ";
    std::cin >> tempNickName;
    if (!check_str(tempNickName))
        return false;

    std::cout << "Phone Number: ";
    std::cin >> tempPhoneNumber;
    if (tempPhoneNumber.find_first_not_of("0123456789") != std::string::npos)
    {
        std::cout << "Invalid phone number" << std::endl;
        return false;
    }

    std::cout << "Darkest Secret: ";

    firstName = tempFirstName;
    lastName = tempLastName;
    nickName = tempNickName;
    phoneNumber = tempPhoneNumber;
    darkestSecret = tempDarkestSecret;

    return true;
}

