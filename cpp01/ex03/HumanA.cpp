/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaiz <vaiz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 15:00:19 by odanyliu          #+#    #+#             */
/*   Updated: 2026/03/29 18:08:07 by vaiz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon &weapon)
: name(name), weapon(weapon)
{}

void	HumanA::attack(void) {
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}