/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:39:06 by bebrandt          #+#    #+#             */
/*   Updated: 2024/11/23 19:39:03 by bebrandt         ###   ########.fr       */
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
    void    update(void);
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

	void	_setContactFirstName(Contact);
	void	_setContactLastName(Contact);
	void	_setContactNickname(Contact);
	void	_setContactPhoneNumber(Contact);
	void	_setContactDarkestSecret(Contact);
};

#endif
