/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:39:09 by bebrandt          #+#    #+#             */
/*   Updated: 2024/11/07 19:43:48 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
    this->tab = 8;
    std::cout << "This is the constructor called" << std::endl;
}

PhoneBook::~PhoneBook(void)
{
    std::cout << "This is the destructor called" << std::endl;
}

void    PhoneBook::add(void)
{
    std::cout << "This is the add method" << std::endl;
    std::cout << "Tab: " << this->tab << std::endl;
}

void    PhoneBook::search(void)
{
    std::cout << "This is the search method" << std::endl;
    std::cout << "Tab: " << this->tab << std::endl;
}

void    PhoneBook::exit(void)
{
    std::cout << "This is the exit method" << std::endl;  
}