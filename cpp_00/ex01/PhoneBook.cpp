/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:39:09 by bebrandt          #+#    #+#             */
/*   Updated: 2024/11/25 19:06:52 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
: _nbContacts(0), _contactToUpdate(0) , _maxContacts(8), _sizeFixed(true), _full(false)
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

	contactToSet = (_nbContacts < _maxContacts) ? _nbContacts : _contactToUpdate;
	_setContactAttribute(_getContactAtIndex(contactToSet), &Contact::setFirstName, firstNameMsg);
	_setContactAttribute(_getContactAtIndex(contactToSet), &Contact::setLastName, lastNameMsg);
	_setContactAttribute(_getContactAtIndex(contactToSet), &Contact::setNickname, nicknameMsg);
	_setContactAttribute(_getContactAtIndex(contactToSet), &Contact::setPhoneNumber, phoneNumberMsg);
	_setContactAttribute(_getContactAtIndex(contactToSet), &Contact::setDarkestSecret, darkestSecretMsg);
	if (_nbContacts < _maxContacts)
		_nbContacts++;
	else
	{
    	std::cout << CYAN << "Contact number " << _contactToUpdate + 1 << " is replaced\n" << RESET << std::endl;
		if (_contactToUpdate < (_maxContacts - 1))
			_contactToUpdate++;
		else
			_contactToUpdate = 0;
	}
	if (std::cin.good())
		std::cout << CYAN << "There is " << _nbContacts << " contact in your Phone Book" << RESET << std::endl;
}

void    PhoneBook::search(void)
{
	int	indexToDisplay;

	if (_nbContacts == 0)
	{
		std::cout << "Your phone book directory is empty, add some contact to display it" << std::endl;
		return;
	}
    _displayIndexedContacts();
	indexToDisplay = _askUserContactToDisplay();
	if (std::cin.good())
    	_displayContactInfo(_getContactAtIndex(indexToDisplay));
}

void    PhoneBook::exit(void)
{
    std::cout << "Goodbye" << std::endl;
}

Contact&	PhoneBook::_getContactAtIndex(int i)
{
	return (_contacts[i]);
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

	horizontalSep.insert(0, 45, '-').append("\n");
	std::cout << horizontalSep << title << horizontalSep;
	for  (int i = 0; i < _nbContacts; i++)
	{
		std::cout	<< "|    " << i + 1 << "     |" 
					<< _contacts[i].getFirstName(_sizeFixed).append("|") 
					<< _contacts[i].getLastName(_sizeFixed).append("|") 
					<< _contacts[i].getNickname(_sizeFixed).append("|") 
					<< '\n' 
					<< horizontalSep;
	}
}

int	PhoneBook::_askUserContactToDisplay(void) const
{
	std::string const	msg {"Choose an index to display a contact:"};
	std::string const	wrongInput {"Please, your input should contain only one numeric character\n"};
	std::string const	indexOutOfRange {"The index you choose is out of Range. Please select an index between "};
	int					index;

	while(std::cin.good())
	{
		std::cout << msg << std::endl;
		std::cin >> index;
		if (std::cin.fail())
		{
			if (std::cin.eof())
				break;
			else
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << YELLOW << wrongInput << RESET << std::endl;
				continue;
			}
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (std::cin.gcount() > 1)
        {
			std::cout << YELLOW << wrongInput << RESET << std::endl;
            continue;
        }
		if (--index < _nbContacts)
			return (index);
		else
			std::cout << YELLOW << indexOutOfRange << "1 and " << _nbContacts << RESET << std::endl;
	}
	return (0);
}

void	PhoneBook::_displayContactInfo(Contact& contact)
{
	std::cout	<< "First name:\t" << contact.getFirstName(_full) << '\n'
				<< "Last name:\t" << contact.getLastName(_full) << '\n'
				<< "Nickname:\t" << contact.getNickname(_full) << '\n'
				<< "Phone number:\t" << contact.getPhoneNumber(_full) << '\n'
				<< "Darkest secret:\t" << contact.getDarkestSecret(_full) << std::endl;
}
