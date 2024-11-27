/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timestamp.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 20:48:33 by bebrandt          #+#    #+#             */
/*   Updated: 2024/11/27 20:55:12 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>

int	main(void)
{
	time_t timestamp;
	time(&timestamp);
	struct tm datetime = *localtime(&timestamp);

	// Display the date and time represented by the timestamp
	std::cout << ctime(&timestamp) << std::endl;
	std::cout << datetime.tm_hour << std::endl;
}
