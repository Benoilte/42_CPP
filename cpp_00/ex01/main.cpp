/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:21:46 by bebrandt          #+#    #+#             */
/*   Updated: 2024/11/23 19:57:00 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include "color.hpp"
#include <iostream>

void	displayCommand(void)
{
	std::string	const sep {"\n***********************"};
	std::string	const availableCmd {"\n#  AVAILABLE COMMAND  #"};
	std::string	const cmd {"\n# ADD - SEARCH - EXIT #"};

	std::cout	<< sep << availableCmd << sep << cmd << sep << std::endl;
}

int main(void)
{
	PhoneBook   directory;
	std::string input;

	std::cout << "**** Welcome in your Phone Book ****" << std::endl;
	displayCommand();
	while((input.compare("EXIT")) != 0)
	{
		std::getline(std::cin >> std::ws, input);
		if ((input.compare("ADD")) == 0)
		{
			if (directory.getNbContacts() < directory.getMaxContacts())
				directory.add();
			else
				directory.update();

			displayCommand();
		}
		else if ((input.compare("SEARCH")) == 0)
		{
			directory.search();
			displayCommand();
		}
		else if ((input.compare("EXIT")) == 0)
			std::cout << "Goodbye" << std::endl;
		else
		{
			std::cout << RED << "Unknown command try again" << RESET << std::endl;
			displayCommand();
		}

	}
	return (0);
}
