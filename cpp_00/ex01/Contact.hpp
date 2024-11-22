/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:39:14 by bebrandt          #+#    #+#             */
/*   Updated: 2024/11/22 14:05:01 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact
{
	public:

	int tab;

	Contact(void);
	~Contact(void);

	std::string	getFirstName(void) const;
	bool		setFirstName(std::string);

	std::string	getLastName(void) const;
	bool		setLastName(std::string);

	std::string	getNickname(void) const;
	bool		setNickname(std::string);

	std::string	getPhoneNumber(void) const;
	bool		setPhoneNumber(std::string);

	std::string	getDarkestSecret(void) const;
	bool		setDarkestSecret(std::string);

	private:

	std::string	_FirstName;
	std::string	_LastName;
	std::string	_Nickname;
	std::string	_PhoneNumber;
	std::string	_DarkestSecret;
};

#endif