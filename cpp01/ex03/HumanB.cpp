/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaiz <vaiz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 15:00:19 by odanyliu          #+#    #+#             */
/*   Updated: 2026/03/29 18:08:50 by vaiz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name)
: name(name), weapon(NULL) 
{}

void	HumanB::attack(void) {
	if (weapon)
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
	else
		std::cout << name << " cannot attack without a weapon" << std::endl;	
}

void	HumanB::setWeapon(Weapon &_weapon) {
	weapon = &_weapon;
}
