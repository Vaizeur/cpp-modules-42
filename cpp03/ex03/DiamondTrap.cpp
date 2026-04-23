/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaiz <vaiz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 09:40:17 by odanyliu          #+#    #+#             */
/*   Updated: 2026/04/23 10:28:20 by vaiz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : FragTrap("DefaultDiamondTrap_clap_name")
{
	std::string name = "DefaultDiamondTrap";
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 30;
	std::cout << "DiamondTrap default constructor"<< std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap(name + "_clap_name"), ScavTrap(name + "_clap_name"), FragTrap(name + "_clap_name")
{
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 30;
	std::cout << "DiamondTrap constructor" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : 
	ClapTrap(other), ScavTrap(other), FragTrap(other)
{
	this->_name = other._name;
	this->_hitPoints = other.getHitPoints();
	this->_energyPoints = other.getEnergyPoints();
	this->_attackDamage = other.getAttackDamage();
	ClapTrap::_name = other.getName();
	std::cout << "DiamondTrap copy constructor"<< std::endl;
}
DiamondTrap& DiamondTrap::operator=(const DiamondTrap &other)
{
	if (this == &other)
		return (*this);
	this->_name = other._name;
	this->_hitPoints = other.getHitPoints();
	this->_energyPoints = other.getEnergyPoints();
	this->_attackDamage = other.getAttackDamage();
	ClapTrap::_name = other.getName();
	return (*this);
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap destructor"<< std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void    DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap _name = " << this->_name << std::endl;
	std::cout << "ClapTrap _name = " << ClapTrap::_name << std::endl;
}