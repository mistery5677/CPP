/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miafonso <miafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:15:17 by miafonso          #+#    #+#             */
/*   Updated: 2025/03/03 13:14:01 by miafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		if (std::isdigit(str[i]) || str[i] == ' ')
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
    std::string tempFirstName, tempLastName, tempNickName, tempPhoneNumber;

    std::cout << "First Name: ";
    std::getline(std::cin, tempFirstName);
    if (!check_str(tempFirstName))
        return false;

    std::cout << "Last Name: ";
    std::getline(std::cin, tempLastName);
    if (!check_str(tempLastName))
        return false;

    std::cout << "Nickname: ";
    std::getline(std::cin, tempNickName);
    if (!check_str(tempNickName))
        return false;

    std::cout << "Phone Number: ";
    std::getline(std::cin, tempPhoneNumber);
    if (tempPhoneNumber.find_first_not_of("0123456789") != std::string::npos)
    {
        std::cout << "Invalid phone number" << std::endl;
        return false;
    }

    std::cout << "Darkest Secret: ";
    std::getline(std::cin, darkestSecret);
    
    firstName = tempFirstName;
    lastName = tempLastName;
    nickName = tempNickName;
    phoneNumber = tempPhoneNumber;

    return true;
}

