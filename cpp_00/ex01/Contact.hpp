/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:39:14 by bebrandt          #+#    #+#             */
/*   Updated: 2024/11/28 14:21:32 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include "color.hpp"
#include <iostream>
#include <string>

class Contact
{
	public:

	Contact(void);
	~Contact(void);

	std::string	getFirstName(bool sizeOfTen) const;
	bool		setFirstName(std::string);

	std::string	getLastName(bool sizeOfTen) const;
	bool		setLastName(std::string);

	std::string	getNickname(bool sizeOfTen) const;
	bool		setNickname(std::string);

	std::string	getPhoneNumber(bool sizeOfTen) const;
	bool		setPhoneNumber(std::string);

	std::string	getDarkestSecret(bool sizeOfTen) const;
	bool		setDarkestSecret(std::string);

	private:

	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickname;
	std::string	_phoneNumber;
	std::string	_darkestSecret;

	std::string	_getAttributeWithFixedSize(std::string attribute) const;
	bool		_attributeIsEmpty(std::string attribute, std::string attributeName) const;
	bool		_attributeHasSpace(std::string attribute, std::string attributeName) const;
	bool		_attributeContainNotOnlyDigit(std::string attribute, std::string attributeName) const;
};

#endif
