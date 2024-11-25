/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:39:09 by bebrandt          #+#    #+#             */
/*   Updated: 2024/11/25 15:17:17 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <limits>
#include "PhoneBook.hpp"
#include "color.hpp"

PhoneBook::PhoneBook(void)
: _nbContacts(0), _contactToUpdate(0) , _maxContacts(8), _sizeOfTen(true), _full(false)
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
	int					contactToSet;

	contactToSet = (this->_nbContacts < this->_maxContacts) ? this->_nbContacts : this->_contactToUpdate;
	this->_setContactAttribute(this->getContactAtIndex(contactToSet), &Contact::setFirstName, firstNameMsg);
	this->_setContactAttribute(this->getContactAtIndex(contactToSet), &Contact::setLastName, lastNameMsg);
	this->_setContactAttribute(this->getContactAtIndex(contactToSet), &Contact::setNickname, nicknameMsg);
	this->_setContactAttribute(this->getContactAtIndex(contactToSet), &Contact::setPhoneNumber, phoneNumberMsg);
	this->_setContactAttribute(this->getContactAtIndex(contactToSet), &Contact::setDarkestSecret, darkestSecretMsg);
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
    this->_displayIndexedContacts();
}

void    PhoneBook::exit(void)
{
    std::cout << "This is the exit method" << std::endl;
}

Contact&	PhoneBook::getContactAtIndex(int i)
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

void	PhoneBook::_setContactAttribute(Contact& contact, bool (Contact::*set)(std::string), std::string msg)
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
			else
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
		}
		attributeValue.erase(attributeValue.find_last_not_of(" \t\n\r\f\v") + 1);
		if ((contact.*set)(attributeValue))
			isSet = true;
	}
}

void	PhoneBook::_displayIndexedContacts(void) const
{
	std::string horizontalSep;
	std::string const	title {"|  INDEX   |FIRST NAME|LAST  NAME| NICKNAME |\n"};
	std::string index {"|    1     |"};

	if (this->_nbContacts == 0)
	{
		std::cout << "Your phone book directory is empty, add some contact to display it" << std::endl;
		return;
	}
	horizontalSep.insert(0, 45, '-').append("\n");
	std::cout << horizontalSep << title << horizontalSep;
	for  (int i = 0; i < this->_nbContacts; i++)
	{
		std::cout	<< index.replace(5, 1, std::to_string(i + 1)) 
					<< this->_contacts[i].getFirstName(this->_sizeOfTen).append("|") 
					<< this->_contacts[i].getLastName(this->_sizeOfTen).append("|") 
					<< this->_contacts[i].getNickname(this->_sizeOfTen).append("|") 
					<< '\n' 
					<< horizontalSep;
	}
}

