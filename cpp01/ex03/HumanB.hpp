/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odanyliu <odanyliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 15:00:19 by odanyliu          #+#    #+#             */
/*   Updated: 2026/02/24 15:33:22 by odanyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
#define HUMANB_H
#include "Weapon.hpp"

class HumanB
{
	private:
		std::string	name;
		Weapon      *weapon;
	public:
		void attack();
		HumanB(std::string _name);
		void	setWeapon(Weapon &_weapon);
};

#endif