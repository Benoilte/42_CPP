/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:39:20 by bebrandt          #+#    #+#             */
/*   Updated: 2024/11/07 09:03:15 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

void	loud_and_unbearable_noise()
{
	std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
}

void	megaphone(std::string const& str)
{
	std::cout << str << std::endl;
}

int	main(int argc, char* argv[])
{
	if (argc < 2)
		loud_and_unbearable_noise();
	else
	{
		for (int i = 1; i < argc; i++)
			megaphone(argv[i]);
	}
	return (0);
}
