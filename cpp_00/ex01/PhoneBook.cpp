/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:39:09 by bebrandt          #+#    #+#             */
/*   Updated: 2024/11/22 16:09:56 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
    this->_NbContacts = 0;
    // std::cout << "This is the PhoneBook constructor" << std::endl;
}

PhoneBook::~PhoneBook(void)
{
    // std::cout << "This is the PhoneBook destructor" << std::endl;
}

void    PhoneBook::add(void)
{
    std::cout << "This is the add method" << std::endl;
}

void    PhoneBook::search(void) const
{
    std::cout << "This is the search method" << std::endl;
}

void    PhoneBook::exit(void)
{
    std::cout << "This is the exit method" << std::endl;
}
