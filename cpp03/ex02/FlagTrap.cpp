/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FlagTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odanyliu <odanyliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 19:51:11 by vaiz              #+#    #+#             */
/*   Updated: 2026/04/01 11:58:11 by odanyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FlagTrap.hpp"

FlagTrap::FlagTrap(void)
{
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FlagTrap default constructor" << std::endl;
}

FlagTrap::FlagTrap(std::string name)
{
	this->_name = name;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FlagTrap constructor" << std::endl;
}

FlagTrap &FlagTrap::operator=(const FlagTrap &other)
{
	this->_name = other.getName();
	this->_hitPoints = other.getHitPoints();
	this->_energyPoints = other.getEnergyPoints();
	this->_attackDamage = other.getAttackDamage();
	std::cout << "FlagTrap Copy assignment operator " << std::endl;
	return (*this);
}

FlagTrap::FlagTrap(FlagTrap &other)
{
	this->_name = other.getName();
	this->_hitPoints = other.getHitPoints();
	this->_energyPoints = other.getEnergyPoints();
	this->_attackDamage = other.getAttackDamage();
	std::cout << "FlagTrap copy constructor" << std::endl;
}

FlagTrap::~FlagTrap()
{
	std::cout << "FlagTrap destructor" << std::endl;
}

void FlagTrap::highFivesGuys(void)
{
    std::cout << "FragTrap requests a positive high five! ✋" << std::endl;	
}