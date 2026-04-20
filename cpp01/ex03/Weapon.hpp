/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odanyliu <odanyliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 14:58:02 by odanyliu          #+#    #+#             */
/*   Updated: 2026/04/20 11:07:03 by odanyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
#define WEAPON_H
#include <string>

class Weapon
{
	private:
		std::string type;
	public:
		std::string	getType(void) const;
		void		setType(std::string value);
		Weapon(std::string _type);
		Weapon();
};

#endif