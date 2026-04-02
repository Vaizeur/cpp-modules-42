/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odanyliu <odanyliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 10:50:00 by odanyliu          #+#    #+#             */
/*   Updated: 2026/04/02 12:01:58 by odanyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	this->_name = "DefaultScavTrap"; 
	this->_hitPoints = 100; 
	this->_energyPoints = 50; 
	this->_attackDamage = 20;
	std::cout << "ScavTrap default constructor" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_hitPoints = 100; 
	this->_energyPoints = 50; 
	this->_attackDamage = 20;
	std::cout << "ScavTrap constructor" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other)
{
	this->_name = other.getName();
	this->_hitPoints = other.getHitPoints();
	this->_energyPoints = other.getEnergyPoints();
	this->_attackDamage = other.getAttackDamage();
	std::cout << "ScavTrap copy constructor" << std::endl;
}

ScavTrap	 &ScavTrap::operator=(const ScavTrap &other)
{
	if (this == &other)
		return (*this);
	this->_name = other.getName();
	this->_hitPoints = other.getHitPoints();
	this->_energyPoints = other.getEnergyPoints();
	this->_attackDamage = other.getAttackDamage();
	std::cout << "ScavTrap Copy assignment operator " << std::endl;
	return (*this);
}


void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->_name << " is now in guard state" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (!this->check())
		return ;	
	std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing "<< this->_attackDamage << " points of damage!" << std::endl;
	this->_energyPoints--;
}

bool ScavTrap::check(void)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "ScavTrap " << this->_name << " has no more hitpoint !" << std::endl;
		return (false);
	}
	if (this->_energyPoints <= 0)
	{
		std::cout << "ScavTrap " << this->_name << " has no more energy !" << std::endl;
		return (false);
	}
	return (true);
}