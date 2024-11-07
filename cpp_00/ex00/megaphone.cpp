/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:39:20 by bebrandt          #+#    #+#             */
/*   Updated: 2024/11/07 11:24:01 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

void	loud_and_unbearable_noise()
{
	std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
}

void	megaphone(std::string str)
{
	size_t	len { str.length() };

    for (size_t i = 0; i < len; i++) { 
        str[i] = std::toupper(str[i]); 
    }
	std::cout << str;
}

int	main(int argc, char* argv[])
{
	if (argc < 2)
		loud_and_unbearable_noise();
	else
	{
		for (int i = 1; i < argc; i++)
			megaphone(argv[i]);
		std::cout << std::endl; 
	}
	return (0);
}
