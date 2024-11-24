/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:39:09 by bebrandt          #+#    #+#             */
/*   Updated: 2024/11/23 19:58:55 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"
#include "color.hpp"

PhoneBook::PhoneBook(void)
: _nbContacts(0), _contactToUpdate(0) , _maxContacts(8)
{
    // std::cout << "This is the PhoneBook constructor" << std::endl;
}

PhoneBook::~PhoneBook(void)
{
    // std::cout << "This is the PhoneBook destructor" << std::endl;
}

void    PhoneBook::add(void)
{
	this->_setContactFirstName(getContactAtIndex(this->_nbContacts));
	this->_setContactLastName(getContactAtIndex(this->_nbContacts));
	this->_setContactNickname(getContactAtIndex(this->_nbContacts));
	this->_setContactPhoneNumber(getContactAtIndex(this->_nbContacts));
	this->_setContactDarkestSecret(getContactAtIndex(this->_nbContacts));
	this->_nbContacts++;
    std::cout << "There is " << this->_nbContacts << " contact in your Phone Book" << std::endl;
}

void    PhoneBook::update(void)
{
    std::cout << "Update Contact number " << this->_contactToUpdate + 1 << std::endl;
	if (this->_contactToUpdate < (this->_maxContacts - 1))
		this->_contactToUpdate++;
	else
		this->_contactToUpdate = 0;
}

void    PhoneBook::search(void) const
{
    std::cout << "This is the search method" << std::endl;
}

void    PhoneBook::exit(void)
{
    std::cout << "This is the exit method" << std::endl;
}

Contact	PhoneBook::getContactAtIndex(int i) const
{
	return (this->_contacts[i]);
}

int	PhoneBook::getNbContacts(void) const
{
	return (this->_nbContacts);
}

int	PhoneBook::getMaxContacts(void) const
{
	return (this->_maxContacts);
}

void	PhoneBook::_setContactFirstName(Contact contact)
{
	std::string	firstName;
	int			counter;

	counter = 0;
	while(counter == 0)
	{
		std::cout << "Write your first name (Characters without space):" << std::endl;
		std::getline(std::cin >> std::ws, firstName);
		firstName.erase(firstName.find_last_not_of(" \t\n\r\f\v") + 1);
		if (contact.setFirstName(firstName))
			counter++;
	}
}

void	PhoneBook::_setContactLastName(Contact contact)
{
	std::string	lastName;
	int			counter;

	counter = 0;
	while(counter == 0)
	{
		std::cout << "Write your last name (Characters without space):" << std::endl;
		std::getline(std::cin >> std::ws, lastName);
		lastName.erase(lastName.find_last_not_of(" \t\n\r\f\v") + 1);
		if (contact.setLastName(lastName))
			counter++;

	}
}

void	PhoneBook::_setContactNickname(Contact contact)
{
	std::string	nickname;
	int			counter;

	counter = 0;
	while(counter == 0)
	{
		std::cout << "Write your nickname (Characters without space):" << std::endl;
		std::getline(std::cin >> std::ws, nickname);
		nickname.erase(nickname.find_last_not_of(" \t\n\r\f\v") + 1);
		if (contact.setNickname(nickname))
			counter++;

	}
}

void	PhoneBook::_setContactPhoneNumber(Contact contact)
{
	std::string	phoneNumber;
	int			counter;

	counter = 0;
	while(counter == 0)
	{
		std::cout << "Write your Phone Number (Only digit characters):" << std::endl;
		std::getline(std::cin >> std::ws, phoneNumber);
		phoneNumber.erase(phoneNumber.find_last_not_of(" \t\n\r\f\v") + 1);
		if (contact.setPhoneNumber(phoneNumber))
			counter++;

	}
}

void	PhoneBook::_setContactDarkestSecret(Contact contact)
{
	std::string	darkestSecret;
	int			counter;

	counter = 0;
	while(counter == 0)
	{
		std::cout << "Write your darkest secret" << std::endl;
		std::getline(std::cin >> std::ws, darkestSecret);
		darkestSecret.erase(darkestSecret.find_last_not_of(" \t\n\r\f\v") + 1);
		if (contact.setDarkestSecret(darkestSecret))
			counter++;
	}
}
