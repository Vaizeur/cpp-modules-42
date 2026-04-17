/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odanyliu <odanyliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 10:02:49 by odanyliu          #+#    #+#             */
/*   Updated: 2026/04/17 14:38:25 by odanyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug(void) {
	std::cout << "[DEBUG]" << std::endl << "The steak temperature is below what I expect. This is not serious at all!" << std::endl;
}

void Harl::info(void) {
	std::cout << "[INFO]" << std::endl << "I'm not asking for the moon, just a properly prepared burger with the options I chose." << std::endl;
}

void Harl::warning(void) {
	std::cout << "[WARNING]" << std::endl << "I’m willing to be understanding, but there are limits." << std::endl;
}

void Harl::error(void) {
	std::cout << "[ERROR]" << std::endl << "Call the manager immediately!" << std::endl;
}

int	Harl::getLevelIndex(std::string level)
{
	std::string list[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	for (size_t i = 0; i < 4; i++)
	{
		if (level == list[i])
			return (i);		
	}
	return (-1);
}

void Harl::complain(std::string level)
{
	switch (getLevelIndex(level))
	{
		case 0:
			debug();
			/* fallthrough */
		case 1 :
			info();
			/* fallthrough */
		case 2 :
			warning();
			/* fallthrough */
		case 3 :
			error();
			break;
		default:
			std::cout << "This is ridiculous! I clearly said DEBUG, INFO, WARNING, or ERROR. Try again properly!" << std::endl;
			break;
	}
}