/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:39:06 by bebrandt          #+#    #+#             */
/*   Updated: 2024/11/25 19:06:52 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <limits>
#include <sstream>
#include "color.hpp"
#include "Contact.hpp"

class PhoneBook
{
	public:

	PhoneBook(void);
	~PhoneBook(void);

	void		add(void);
	void		search(void);
	void		exit(void);

	private:

	Contact		_contacts[8];
	int			_nbContacts;
	int			_contactToUpdate;
	int	const	_maxContacts;
	bool const	_sizeFixed;
	bool const	_full;

	Contact&	_getContactAtIndex(int i);
	void		_setContactAttribute(	Contact& contact,
										bool (Contact::*set)(std::string),
										std::string msg);
	void		_displayIndexedContacts(void) const;
	int			_askUserContactToDisplay(void) const;
	void		_displayContactInfo(Contact& contact);
};

#endif
