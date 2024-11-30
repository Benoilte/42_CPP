/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 13:30:45 by bebrandt          #+#    #+#             */
/*   Updated: 2024/11/30 15:01:46 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int n, std::string name);

int	main(void)
{
	Zombie	*zombies;
	int		i;
	int		zombiesCount;

	// create a Horde of 4 zombies called John, annouced themselves and delete them.
	zombiesCount = 4;
	zombies = zombieHorde(zombiesCount, "John");
	if (zombies == NULL) return (1);
	for (i = 0; i < zombiesCount; i++)
		zombies[i].announce();
	delete [] zombies;
	// create a Horde of 8 zombies called Marc, annouced themselves and delete them.
	zombiesCount = 8;
	zombies = zombieHorde(zombiesCount, "Marc");
	if (zombies == NULL) return (2);
	for (i = 0; i < zombiesCount; i++)
		zombies[i].announce();
	delete [] zombies;
	return (0);
}
