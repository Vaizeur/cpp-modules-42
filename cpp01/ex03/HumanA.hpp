/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odanyliu <odanyliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 15:00:19 by odanyliu          #+#    #+#             */
/*   Updated: 2026/02/24 15:32:21 by odanyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
#define HUMANA_H
#include "Weapon.hpp"

class HumanA
{
	private:
		std::string	name;
		Weapon      &weapon;
	public:
		void attack();
		HumanA(std::string name, Weapon &weapon);
};

#endif