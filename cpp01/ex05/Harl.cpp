/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaiz <vaiz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 10:02:49 by odanyliu          #+#    #+#             */
/*   Updated: 2026/03/29 18:03:15 by vaiz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug(void) {
	std::cout << "[DEBUG]" << "The steak temperature is below what I expect. This is not serious at all!" << std::endl;
}

void Harl::info(void) {
	std::cout << "[INFO]" << "I'm not asking for the moon, just a properly prepared burger with the options I chose." << std::endl;
}

void Harl::warning(void) {
	std::cout << "[WARNING]" << "I’m willing to be understanding, but there are limits." << std::endl;
}

void Harl::error(void) {
	std::cout << "[ERROR]" << "Call the manager immediately!" << std::endl;
}

void Harl::complain(std::string level)
{
	std::pair<std::string, void (Harl::*)()> list[4] = {
		{"DEBUG", &Harl::debug},
		{"INFO", &Harl::info},
		{"WARNING", &Harl::warning},
		{"ERROR", &Harl::error}
	};
	for (size_t i = 0; i < 4; i++)
	{
		if (level == list[i].first)
		{
			(this->*list[i].second)();
			return ;
		}
	}
	std::cout << "This is ridiculous! I clearly said DEBUG, INFO, WARNING, or ERROR. Try again properly!" << std::endl;
}