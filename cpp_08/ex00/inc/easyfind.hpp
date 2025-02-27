/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <bebrandt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:35:13 by bebrandt          #+#    #+#             */
/*   Updated: 2025/02/27 21:52:13 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <exception>

template < typename T >
typename T::iterator easyfind(T container, int n)
{
    typename T::iterator it = std::find(container.begin(), container.end(), n);
    if (it != container.end())
        return it;
    throw std::runtime_error("Value is not find in container");
}

#endif