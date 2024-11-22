/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:39:17 by bebrandt          #+#    #+#             */
/*   Updated: 2024/11/22 16:09:10 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"

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
	this->_FirstName = FirstName;
	return (0);
}

std::string	Contact::getLastName(void) const
{
	return (this->_LastName);
}

bool	Contact::setLastName(std::string LastName)
{
	this->_LastName = LastName;
	return (0);
}

std::string	Contact::getNickname(void) const
{
	return (this->_Nickname);
}

bool	Contact::setNickname(std::string Nickname)
{
	this->_Nickname = Nickname;
	return (0);
}

std::string	Contact::getPhoneNumber(void) const
{
	return (this->_PhoneNumber);
}

bool	Contact::setPhoneNumber(std::string PhoneNumber)
{
	this->_PhoneNumber = PhoneNumber;
	return (0);
}

std::string	Contact::getDarkestSecret(void) const
{
	return (this->_DarkestSecret);
}

bool	Contact::setDarkestSecret(std::string DarkestSecret)
{
	this->_DarkestSecret = DarkestSecret;
	return (0);
}
