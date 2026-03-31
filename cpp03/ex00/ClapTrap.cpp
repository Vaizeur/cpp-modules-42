/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaiz <vaiz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 19:51:11 by vaiz              #+#    #+#             */
/*   Updated: 2026/03/31 20:10:29 by vaiz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : 
	_name("NoName") , 
	_hitPoints(10) , 
	_energyPoints(10) , 
	_attackDamage(0)
{
	std::cout << "ClapTrap constructor void " << std::endl;
}

ClapTrap::ClapTrap(std::string name) :
	_name(name) , 
	_hitPoints(10) , 
	_energyPoints(10) , 
	_attackDamage(0)
{ 
	std::cout << "ClapTrap constructor name " << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	// TODO : A FAIRE
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor" << std::endl;
}

std::string ClapTrap::getName(void) const  {
	return (this->_name);
}

int ClapTrap::getHitPoints(void) const  {
	return (this->_hitPoints);
}

int ClapTrap::getEnergyPoints(void) const  {
	return (this->_energyPoints);
}

int ClapTrap::getAttackDamage(void) const  {
	return (this->_attackDamage);
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_energyPoints > 0)
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing "<< this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints--;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " has no more energy !" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->_name << " take " << target << " damage ! " << std::endl;
}

