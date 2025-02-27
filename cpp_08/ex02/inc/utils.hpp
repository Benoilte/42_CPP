/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:05:07 by bebrandt          #+#    #+#             */
/*   Updated: 2025/02/27 20:37:12 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <list>

#include "MutantStack.hpp"
#include "colors.hpp"

template< typename T >
void    iterateThroughStack(T it, T ite, std::string const &msg)
{
    ++it;
	--it;
	std::cout << CYAN << msg << RESET << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}

#endif