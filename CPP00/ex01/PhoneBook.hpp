/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miafonso <miafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:01:06 by miafonso          #+#    #+#             */
/*   Updated: 2025/03/03 12:29:41 by miafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	void showContact(int index, Contact contact);
	void findContact();
};
