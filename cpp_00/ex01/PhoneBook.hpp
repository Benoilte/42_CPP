/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:39:06 by bebrandt          #+#    #+#             */
/*   Updated: 2024/11/26 16:23:27 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include "color.hpp"
#include <iostream>
#include <limits>

class PhoneBook
{
	public:

	PhoneBook(void);
	~PhoneBook(void);

	size_t				getBiggestSizeCommand(void) const;

	void				displayAvailableCommands(void) const;
	int					executeCommands(std::string command);

	private:

	std::string const	_addCommand;
	std::string const	_searchCommand;
	std::string const	_exitCommand;
	size_t				_biggestSizeCommand;
	Contact				_contacts[8];
	int					_nbContacts;
	int					_contactToUpdate;
	int	const			_maxContacts;
	bool const			_sizeFixed;
	bool const			_full;

	void				_add(void);
	void				_search(void);
	void				_exit(void);
	void				_unknownCommand(void) const;
	Contact&			_getContactAtIndex(int i);
	void				_setContactAttribute(	Contact& contact,
												bool (Contact::*set)(std::string),
												std::string msg);
	void				_displayIndexedContacts(void) const;
	int					_askUserContactToDisplay(void) const;
	void				_displayContactInfo(Contact& contact);
};

#endif
