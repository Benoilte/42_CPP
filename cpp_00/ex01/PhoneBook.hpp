/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:39:06 by bebrandt          #+#    #+#             */
/*   Updated: 2024/11/24 13:22:13 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
    public:

    PhoneBook(void);
    ~PhoneBook(void);

    void    add(void);
    void    search(void) const;
    void    exit(void);

	int		getNbContacts(void) const;
	int		getMaxContacts(void) const;
	Contact	getContactAtIndex(int i) const;

    private:

    Contact		_contacts[8];
    int     	_nbContacts;
    int     	_contactToUpdate;
	int	const	_maxContacts;


    void	_setContactAttribute(Contact contact, bool (Contact::*set)(std::string), std::string msg);
};

#endif
