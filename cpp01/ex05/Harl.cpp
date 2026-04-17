/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odanyliu <odanyliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 10:02:49 by odanyliu          #+#    #+#             */
/*   Updated: 2026/04/09 16:14:43 by odanyliu         ###   ########.fr       */
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
		std::make_pair("DEBUG",&Harl::debug),
		std::make_pair("INFO",&Harl::info),
		std::make_pair("WARNING",&Harl::warning),
		std::make_pair("ERROR",&Harl::error),
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