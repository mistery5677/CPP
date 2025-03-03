/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miafonso <miafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:00:57 by miafonso          #+#    #+#             */
/*   Updated: 2025/03/03 12:36:03 by miafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class Contact
{
private:
    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string phoneNumber;
    std::string darkestSecret;
public:
    Contact();
    bool setContact();
    bool check_str(std::string str);
    std::string getFirstName() { return firstName; };
    std::string getLastName() { return lastName; };
    std::string getNickName() { return nickName; };
    std::string getPhoneNumber() { return phoneNumber; };
    std::string getDarkestSecret() { return darkestSecret; };
};