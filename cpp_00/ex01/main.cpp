/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:21:46 by bebrandt          #+#    #+#             */
/*   Updated: 2024/11/22 15:33:40 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>

int main(void)
{
	PhoneBook   directory;
	std::string input;

	std::cout << "Welcome in your Phone Book.\nEnter 'ADD' - 'SEARCH' - 'EXIT' " << std::endl;
	while((input.compare("EXIT")) != 0)
	{
		std::getline(std::cin >> std::ws, input);
		if ((input.compare("ADD")) == 0)
		{
			directory.add();
			std::cout << "Enter 'ADD' - 'SEARCH' - 'EXIT' " << std::endl;
		}
		if ((input.compare("SEARCH")) == 0)
		{
			directory.search();
			std::cout << "Enter 'ADD' - 'SEARCH' - 'EXIT' " << std::endl;
		}
	}
	return (0);
}