/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 22:40:33 by bebrandt          #+#    #+#             */
/*   Updated: 2024/11/30 22:51:35 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanB
{
	public:

		HumanB(std::string name);
		~HumanB();

		void	setWeapon(Weapon &weapon);
		void	attack();

	private:

		std::string	_name;
		Weapon		*_weapon;
};

#endif
