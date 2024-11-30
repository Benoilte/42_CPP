/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 22:40:43 by bebrandt          #+#    #+#             */
/*   Updated: 2024/11/30 22:40:44 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

/*
A getType() member function that returns a const reference to type.
• A setType() member function that sets type using the new one passed as parameter.
*/

#include <string>

class Weapon
{
	public:

		Weapon(std::string type);
		~Weapon();

		std::string const	&getType() const;
		void				setType(std::string type);

	private:

		std::string _type;
};

#endif
