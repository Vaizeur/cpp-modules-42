/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odanyliu <odanyliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 14:58:02 by odanyliu          #+#    #+#             */
/*   Updated: 2026/02/24 15:24:57 by odanyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string _type) {
	type = _type;
}

std::string	Weapon::getType(void) {
	return (type);
}

void	Weapon::setType(std::string value) {
	type = value;
}

Weapon::Weapon() {
	type = "";
}

