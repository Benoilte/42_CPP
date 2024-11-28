/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:39:09 by bebrandt          #+#    #+#             */
/*   Updated: 2024/11/28 14:58:40 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
:	_addCommand("ADD"), _searchCommand("SEARCH"), _exitCommand("EXIT"),
	_nbContacts(0), _contactToUpdate(0) , _maxContacts(8),
	_sizeFixed(true), _full(false)
{
	std::string	commands[3] = {_addCommand, _searchCommand, _exitCommand};
	_biggestSizeCommand = 0;
	for (int i = 0; i < 3; i++)
	{
		if (commands[i].length() > _biggestSizeCommand)
			_biggestSizeCommand = commands[i].length();
	}
	std::cout << "\n**** Welcome in your Phone Book ****" << std::endl;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "**** You are exiting your Phone Book - your contacts are lost forever ****" << std::endl;
}

size_t	PhoneBook::getBiggestSizeCommand(void) const
{
	return (_biggestSizeCommand);
}

void	PhoneBook::displayAvailableCommands(void) const
{
	std::string	const sep {"\n***********************"};
	std::string	const availableCmd {"\n#  AVAILABLE COMMAND  #"};
	std::string	const cmd {"\n# ADD - SEARCH - EXIT #"};

	std::cout	<< sep << availableCmd << sep << cmd << sep << std::endl;
}

int	PhoneBook::executeCommands(std::string command)
{
	if ((command.compare(_addCommand)) == 0)
		_add();
	else if ((command.compare(_searchCommand)) == 0)
		_search();
	else if ((command.compare(_exitCommand)) == 0)
	{
		_exit();
		return (-1);
	}
	else
		_unknownCommand();
	return (0);
}

void    PhoneBook::_add(void)
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

void    PhoneBook::_search(void)
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

void    PhoneBook::_exit(void)
{
    std::cout << "Goodbye" << std::endl;
}

void    PhoneBook::_unknownCommand(void) const
{
    std::cout << YELLOW << "Unknown command try again" << RESET << std::endl;
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
		if (!std::getline(std::cin, attributeValue))
		{
			if (std::cin.eof())
				break;
			else
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
		}
		attributeValue.erase(0, attributeValue.find_first_not_of(" \t\n\r\f\v"));
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
		std::cout	<< "|         " << i + 1 << "|"
					<< _contacts[i].getFirstName(_sizeFixed).append("|")
					<< _contacts[i].getLastName(_sizeFixed).append("|")
					<< _contacts[i].getNickname(_sizeFixed).append("|")
					<< '\n'
					<< horizontalSep;
	}
}

int	PhoneBook::_askUserContactToDisplay(void) const
{
	std::string const	msg {"Choose a contact's index to display its informations:"};
	std::string const	emptyInput {"Please, your input should not be empty\n"};
	std::string const	wrongInput {"Your input format is incorrect. Please select an index between "};
	std::string const	indexOutOfRange {"The index you choose is out of Range. Please select an index between "};
	std::string			input;
	int					index;

	while(std::cin.good())
	{
		while(std::cin.good())
		{
			std::cout << msg << std::endl;
			if (!std::getline(std::cin, input))
			{
				if (std::cin.eof())
					break;
				else
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
			}
			input.erase(0, input.find_first_not_of(" \t\n\r\f\v"));
			input.erase(input.find_last_not_of(" \t\n\r\f\v") + 1);
			if (input.length() == 0)
				std::cout << YELLOW << emptyInput << '\n' << RESET << std::endl;
			else if (input.length() > 1 || !std::isdigit(input[0]))
				std::cout << YELLOW << wrongInput << "1 and " << _nbContacts << '\n' << RESET << std::endl;
			else
			{
				index = (int)input[0] - '0';
				if ((--index < _nbContacts) && (index >= 0))
					return (index);
				else
					std::cout << YELLOW << indexOutOfRange << "1 and " << _nbContacts << '\n' << RESET << std::endl;
			}
		}
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
