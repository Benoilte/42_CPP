/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:39:17 by bebrandt          #+#    #+#             */
/*   Updated: 2024/11/25 15:20:23 by bebrandt         ###   ########.fr       */
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

std::string	Contact::getFirstName(bool lengthIsDefine) const
{
	if (lengthIsDefine)
		return (this->_getAttributeWithFixedSize(this->_firstName));
	else
		return (this->_firstName);
}

bool	Contact::setFirstName(std::string firstName)
{
	if (this->_attributeHasSpace(firstName, "first name"))
		return (false);
	this->_firstName = firstName;
	return (true);
}

std::string	Contact::getLastName(bool lengthIsDefine) const
{
	if (lengthIsDefine)
		return (this->_getAttributeWithFixedSize(this->_lastName));
	else
		return (this->_lastName);
}

bool	Contact::setLastName(std::string lastName)
{
	if (this->_attributeHasSpace(lastName, "last name"))
		return (false);
	this->_lastName = lastName;
	return (true);
}

std::string	Contact::getNickname(bool lengthIsDefine) const
{
	if (lengthIsDefine)
		return (this->_getAttributeWithFixedSize(this->_nickname));
	else
		return (this->_nickname);
}

bool	Contact::setNickname(std::string nickname)
{
	if (this->_attributeHasSpace(nickname, "nickname"))
		return (false);
	this->_nickname = nickname;
	return (true);
}

std::string	Contact::getPhoneNumber(bool lengthIsDefine) const
{
	if (lengthIsDefine)
		return (this->_getAttributeWithFixedSize(this->_phoneNumber));
	else
		return (this->_phoneNumber);
}

bool	Contact::setPhoneNumber(std::string phoneNumber)
{
	if (this->_attributeContainOnlyDigit(phoneNumber, "Phone number"))
	{
		this->_phoneNumber = phoneNumber;
		return (true);
	}
	return (false);
}

std::string	Contact::getDarkestSecret(bool lengthIsDefine) const
{
	if (lengthIsDefine)
		return (this->_getAttributeWithFixedSize(this->_darkestSecret));
	else
		return (this->_darkestSecret);
}

bool	Contact::setDarkestSecret(std::string darkestSecret)
{
	this->_darkestSecret = darkestSecret;
	return (true);
}

std::string	Contact::_getAttributeWithFixedSize(std::string attribute) const
{
	size_t const	length {attribute.length()};
	size_t const	fixedSize { 10 };

	if ((length > fixedSize))
		return (attribute.substr(0, 9).append("."));
	else if ((length < fixedSize))
		return (attribute.append((fixedSize - length), ' '));
	else
		return (attribute);
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
