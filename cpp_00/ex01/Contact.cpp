/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:39:17 by bebrandt          #+#    #+#             */
/*   Updated: 2024/11/23 20:06:49 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"
#include "color.hpp"

/*
◦ The contact fields are:

- first name
- last name
- nickname
- phone number
- darkest secret.

A saved contact can’t have empty fields.
*/

Contact::Contact(void)
{
	// std::cout << "This is the Contact constructor" << std::endl;
}

Contact::~Contact(void)
{
	// std::cout << "This is the Contact destructor" << std::endl;
}

std::string	Contact::getFirstName(void) const
{
	return (this->_FirstName);
}

bool	Contact::setFirstName(std::string FirstName)
{
	if (this->_attributeHasSpace(FirstName, "first name"))
		return (false);
	this->_FirstName = FirstName;
	return (true);
}

std::string	Contact::getLastName(void) const
{
	return (this->_LastName);
}

bool	Contact::setLastName(std::string LastName)
{
	if (this->_attributeHasSpace(LastName, "last name"))
		return (false);
	this->_LastName = LastName;
	return (true);
}

std::string	Contact::getNickname(void) const
{
	return (this->_Nickname);
}

bool	Contact::setNickname(std::string Nickname)
{
	if (this->_attributeHasSpace(Nickname, "nickname"))
		return (false);
	this->_Nickname = Nickname;
	return (true);
}

std::string	Contact::getPhoneNumber(void) const
{
	return (this->_PhoneNumber);
}

bool	Contact::setPhoneNumber(std::string PhoneNumber)
{
	if (this->_attributeContainOnlyDigit(PhoneNumber, "Phone number"))
	{
		this->_PhoneNumber = PhoneNumber;
		return (true);
	}
	return (false);
}

std::string	Contact::getDarkestSecret(void) const
{
	return (this->_DarkestSecret);
}

bool	Contact::setDarkestSecret(std::string DarkestSecret)
{
	this->_DarkestSecret = DarkestSecret;
	return (true);
}

bool	Contact::_attributeHasSpace(std::string attribute, std::string attributeName) const
{
	if (attribute.find_first_of(' ') != std::string::npos)
	{
		std::cout << YELLOW << "Please, your " << attributeName << " should not have space\n" << RESET << std::endl;
		return (true);
	}
	else
		return (false);
}

bool	Contact::_attributeContainOnlyDigit(std::string attribute, std::string attributeName) const
{
	size_t	len { attribute.length() };

	for (size_t i = 0; i < len; i++) {
        if (!std::isdigit(attribute[i]))
		{
			std::cout << YELLOW << "Please, your " << attributeName << " should contain only numeric characters\n" << RESET << std::endl;
			return (false);
		}
    }
	return (true);
}

bool	Contact::_attributeContainOnlyAlpha(std::string attribute, std::string attributeName) const
{
	size_t	len { attribute.length() };

	for (size_t i = 0; i < len; i++) {
        if (!std::isalpha(attribute[i]))
		{
			std::cout << YELLOW << "Please, your " << attributeName << " should contain only alphabetic characters\n" << RESET << std::endl;
			return (false);
		}
    }
	return (true);
}
