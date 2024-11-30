/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 22:40:51 by bebrandt          #+#    #+#             */
/*   Updated: 2024/11/30 23:00:53 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon)
{
    /*Constructor*/
}

HumanA::~HumanA()
{
    /*Destructor*/
}

void HumanA::attack(void)
{
	std::cout << _name << " attacks with their weapon " << _weapon.getType() << std::endl;
}
