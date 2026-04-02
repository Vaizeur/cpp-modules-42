/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odanyliu <odanyliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 10:31:15 by odanyliu          #+#    #+#             */
/*   Updated: 2026/04/02 12:00:28 by odanyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

int main()
{
	std::cout << "---- Construction ----" << std::endl;
	DiamondTrap a("lili");

	std::cout << "\n---- Basic actions ----" << std::endl;
	a.attack("lolo");
	a.whoAmI();
	a.guardGate();
	a.highFivesGuys();

	std::cout << "\n---- Copy constructor ----" << std::endl;
	DiamondTrap b(a);
	b.attack("enemy");
	b.whoAmI();
	
	std::cout << "\n---- Assignment operator ----" << std::endl;
	DiamondTrap c;
	c = a;
	c.attack("target");
	c.whoAmI();
	std::cout << "\n---- End of program ----" << std::endl;
	return 0;
}
