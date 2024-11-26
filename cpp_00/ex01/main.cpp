/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:21:46 by bebrandt          #+#    #+#             */
/*   Updated: 2024/11/26 16:21:15 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

void	normalizedInput(std::string& input, size_t sizeMax)
{
	size_t	len;

	input.erase(input.find_last_not_of(" \t\n\r\f\v") + 1);
	len = input.length();
	if (len <= sizeMax)
	{
		for (size_t i = 0; i < len; i++)
			input[i] = std::toupper(input[i]);
	}
}

int main(void)
{
	PhoneBook			directory;
	std::string			input;

	while(std::cin.good())
	{
		directory.displayAvailableCommands();
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
		normalizedInput(input, directory.getBiggestSizeCommand());
		if (directory.executeCommands(input) == -1) break;
	}
	if (std::cin.fail() && std::cin.eof())
		std::cout << YELLOW << "End of file reached - Program will exit" << RESET << std::endl;
	return (0);
}
