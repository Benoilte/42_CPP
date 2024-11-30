/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 22:40:28 by bebrandt          #+#    #+#             */
/*   Updated: 2024/11/30 23:04:23 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL)
{
    /*Constructor*/
}

HumanB::~HumanB()
{
    /*Destructor*/
}

void HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}

void HumanB::attack()
{
	if (_weapon)
		std::cout << _name << " attacks with their weapon " << _weapon->getType() << std::endl;
	else
		std::cout << _name << " attacks without weapon " << std::endl;
}
