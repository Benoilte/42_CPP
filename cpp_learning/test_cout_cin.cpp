/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_cout_cin.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:01:46 by bebrandt          #+#    #+#             */
/*   Updated: 2024/11/28 13:47:39 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>  // for std::cout and std::cin

int main()
{
	std::string input;
	std::cout << "Enter a line of text: ";
	std::getline(std::cin, input);
	std::cout << input << std::endl;
}
