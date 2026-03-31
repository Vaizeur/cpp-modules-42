/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odanyliu <odanyliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 14:58:02 by odanyliu          #+#    #+#             */
/*   Updated: 2026/02/24 15:25:02 by odanyliu         ###   ########.fr       */
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
		std::string	getType(void);
		void		setType(std::string value);
		Weapon(std::string _type);
		Weapon();
};

#endif