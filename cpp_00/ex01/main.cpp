/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:21:46 by bebrandt          #+#    #+#             */
/*   Updated: 2024/11/25 16:10:12 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include "color.hpp"
#include <iostream>
#include <limits>

void	displayCommand(void)
{
	std::string	const sep {"\n***********************"};
	std::string	const availableCmd {"\n#  AVAILABLE COMMAND  #"};
	std::string	const cmd {"\n# ADD - SEARCH - EXIT #"};

	std::cout	<< sep << availableCmd << sep << cmd << sep << std::endl;
}


void	strToUpper(std::string& str)
{
	size_t	len { str.length() };

    for (size_t i = 0; i < len; i++) { 
        str[i] = std::toupper(str[i]); 
    }
}

int main(void)
{
	PhoneBook			directory;
	std::string			input;
	std::string const	addCommand {"ADD"};
	std::string const	exitCommand {"EXIT"};
	std::string const	searchCommand {"SEARCH"};
	size_t const		biggestCommand{searchCommand.length()};

	std::cout << "\n**** Welcome in your Phone Book ****" << std::endl;
	while(std::cin.good() && (input.compare(exitCommand)) != 0)
	{
		displayCommand();
		if (!std::getline(std::cin >> std::ws, input))
		{
			if (std::cin.eof())
				break;
			else
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
		}
		if (input.length() <= biggestCommand)
			strToUpper(input);
		if ((input.compare(addCommand)) == 0)
			directory.add();
		else if ((input.compare(searchCommand)) == 0)
			directory.search();
		else if ((input.compare(exitCommand)) == 0)
			directory.exit();
		else
			std::cout << YELLOW << "Unknown command try again" << RESET << std::endl;

	}
	if (std::cin.fail() && std::cin.eof())
		std::cout << YELLOW << "End of file reached - Program will exit" << RESET << std::endl;
	return (0);
}
