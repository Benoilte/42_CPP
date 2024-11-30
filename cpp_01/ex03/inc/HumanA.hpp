/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 22:40:36 by bebrandt          #+#    #+#             */
/*   Updated: 2024/11/30 23:01:03 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanA
{
	public:

		HumanA(std::string name, Weapon &weapon);
		~HumanA();

		void	attack(void);

	private:

		std::string	_name;
		Weapon		&_weapon;
};

#endif
