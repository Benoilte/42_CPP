/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:21:46 by bebrandt          #+#    #+#             */
/*   Updated: 2024/11/24 17:38:15 by bebrandt         ###   ########.fr       */
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

	std::cout << "\n**** Welcome in your Phone Book ****" << std::endl;
	while(std::cin.good() && (input.compare("EXIT")) != 0)
	{
		displayCommand();
		if (!std::getline(std::cin >> std::ws, input))
		{
			if (std::cin.eof())
				break;
		}
		if ((input.compare("ADD")) == 0)
			directory.add();
		else if ((input.compare("SEARCH")) == 0)
			directory.search();
		else if ((input.compare("EXIT")) == 0)
			std::cout << "Goodbye" << std::endl;
		else
			std::cout << YELLOW << "Unknown command try again" << RESET << std::endl;

	}
	if (std::cin.fail() && std::cin.eof())
		std::cout << YELLOW << "End of file reached - Program will exit" << RESET << std::endl;
	return (0);
}
