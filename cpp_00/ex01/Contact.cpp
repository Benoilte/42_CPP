/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:39:17 by bebrandt          #+#    #+#             */
/*   Updated: 2024/11/28 14:22:58 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

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
		return (_getAttributeWithFixedSize(_firstName));
	else
		return (_firstName);
}

bool	Contact::setFirstName(std::string firstName)
{
	if (_attributeIsEmpty(firstName, "first name") || _attributeHasSpace(firstName, "first name"))
		return (false);
	_firstName = firstName;
	return (true);
}

std::string	Contact::getLastName(bool lengthIsDefine) const
{
	if (lengthIsDefine)
		return (_getAttributeWithFixedSize(_lastName));
	else
		return (_lastName);
}

bool	Contact::setLastName(std::string lastName)
{
	if (_attributeIsEmpty(lastName, "last name") || _attributeHasSpace(lastName, "last name"))
		return (false);
	_lastName = lastName;
	return (true);
}

std::string	Contact::getNickname(bool lengthIsDefine) const
{
	if (lengthIsDefine)
		return (_getAttributeWithFixedSize(_nickname));
	else
		return (_nickname);
}

bool	Contact::setNickname(std::string nickname)
{
	if (_attributeIsEmpty(nickname, "nickname") || _attributeHasSpace(nickname, "nickname"))
		return (false);
	_nickname = nickname;
	return (true);
}

std::string	Contact::getPhoneNumber(bool lengthIsDefine) const
{
	if (lengthIsDefine)
		return (_getAttributeWithFixedSize(_phoneNumber));
	else
		return (_phoneNumber);
}

bool	Contact::setPhoneNumber(std::string phoneNumber)
{
	if (_attributeIsEmpty(phoneNumber, "Phone number") || _attributeContainNotOnlyDigit(phoneNumber, "Phone number"))
		return (false);
	_phoneNumber = phoneNumber;
	return (true);
}

std::string	Contact::getDarkestSecret(bool lengthIsDefine) const
{
	if (lengthIsDefine)
		return (_getAttributeWithFixedSize(_darkestSecret));
	else
		return (_darkestSecret);
}

bool	Contact::setDarkestSecret(std::string darkestSecret)
{
	if (_attributeIsEmpty(darkestSecret, "darkest secret")) return (false);
	_darkestSecret = darkestSecret;
	return (true);
}

std::string	Contact::_getAttributeWithFixedSize(std::string attribute) const
{
	size_t const	length {attribute.length()};
	size_t const	fixedSize { 10 };

	if ((length > fixedSize))
		return (attribute.substr(0, 9).append("."));
	else if ((length < fixedSize))
		return (attribute.insert(0, (fixedSize - length), ' '));
	else
		return (attribute);
}

bool	Contact::_attributeIsEmpty(std::string attribute, std::string attributeName) const
{
	if (attribute.empty())
	{
		std::cout << YELLOW << "Please, your " << attributeName << " should not be empty\n" << RESET << std::endl;
		return (true);
	}
	return (false);
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

bool	Contact::_attributeContainNotOnlyDigit(std::string attribute, std::string attributeName) const
{
	size_t	len { attribute.length() };

	for (size_t i = 0; i < len; i++) {
        if (!std::isdigit(attribute[i]))
		{
			std::cout << YELLOW << "Please, your " << attributeName << " should contain only numeric characters\n" << RESET << std::endl;
			return (true);
		}
    }
	return (false);
}
