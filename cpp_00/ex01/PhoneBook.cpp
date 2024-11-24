/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:39:09 by bebrandt          #+#    #+#             */
/*   Updated: 2024/11/24 17:32:49 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <limits>
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
	std::string const	firstNameMsg {"Write your first name (Characters without space):"};
	std::string const	lastNameMsg {"Write your last name (Characters without space):"};
	std::string const	nicknameMsg {"Write your nickname (Characters without space):"};
	std::string const	phoneNumberMsg {"Write your Phone Number (Only digit characters):"};
	std::string const	darkestSecretMsg {"Write your darkest secret:"};
	int			contactToSet;
	
	contactToSet = (this->_nbContacts < this->_maxContacts) ? this->_nbContacts : this->_contactToUpdate;
	this->_setContactAttribute(getContactAtIndex(contactToSet), &Contact::setFirstName, firstNameMsg);
	this->_setContactAttribute(getContactAtIndex(contactToSet), &Contact::setLastName, lastNameMsg);
	this->_setContactAttribute(getContactAtIndex(contactToSet), &Contact::setNickname, nicknameMsg);
	this->_setContactAttribute(getContactAtIndex(contactToSet), &Contact::setPhoneNumber, phoneNumberMsg);
	this->_setContactAttribute(getContactAtIndex(contactToSet), &Contact::setDarkestSecret, darkestSecretMsg);
	if (this->_nbContacts < this->_maxContacts)
		this->_nbContacts++;
	else
	{
    	std::cout << CYAN << "Contact number " << this->_contactToUpdate + 1 << " is replaced\n" << RESET << std::endl;
		if (this->_contactToUpdate < (this->_maxContacts - 1))
			this->_contactToUpdate++;
		else
			this->_contactToUpdate = 0;
	}
	if (std::cin.good())
		std::cout << CYAN << "There is " << this->_nbContacts << " contact in your Phone Book" << RESET << std::endl;
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

void	PhoneBook::_setContactAttribute(Contact contact, bool (Contact::*set)(std::string), std::string msg)
{
	std::string	attributeValue;
	bool		isSet;

	isSet = false;
	while(std::cin.good() && !isSet)
	{
		std::cout << msg << std::endl;
		if (!std::getline(std::cin >> std::ws, attributeValue))
		{
			if (std::cin.eof())
				break;
		}
		attributeValue.erase(attributeValue.find_last_not_of(" \t\n\r\f\v") + 1);
		if ((contact.*set)(attributeValue))
			isSet = true;
	}
}
