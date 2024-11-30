/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 22:40:56 by bebrandt          #+#    #+#             */
/*   Updated: 2024/11/30 22:55:29 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type)
{
    /*Constructor*/
}

Weapon::~Weapon()
{
    /*Destructor*/
}

std::string const& Weapon::getType() const
{
	std::string const	&typeRef {_type};

	return typeRef;
}

void Weapon::setType(std::string type)
{
	_type = type;
}
