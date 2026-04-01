/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odanyliu <odanyliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 16:04:25 by odanyliu          #+#    #+#             */
/*   Updated: 2026/04/01 16:17:31 by odanyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMOND_TRAP_H
# define DIAMOND_TRAP_H
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public FragTrap , public ScavTrap
{
	private:
		std::string _name;
	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(DiamondTrap &other);
		DiamondTrap &operator=(DiamondTrap &other);
		~DiamondTrap();
};

DiamondTrap::DiamondTrap(void)
{
	std::string name = "DefaultDiamondTrap";

	this->_name = name;
	ScavTrap::_name = name.append("_new_name");
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap default constructor"<< std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
{
	this->_name = name;
	ScavTrap::_name = name.append("_new_name");
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap constructor"<< std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
	
}
#endif