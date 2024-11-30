/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 13:30:37 by bebrandt          #+#    #+#             */
/*   Updated: 2024/11/30 15:02:05 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int n, std::string name)
{
	Zombie	*zombies;

	try {
		zombies = new Zombie[n];
	} catch (std::bad_alloc&) {
		return (NULL);
	}
	for (int i = 0; i < n; i++)
		zombies[i].setName(name);
	return (zombies);
}
