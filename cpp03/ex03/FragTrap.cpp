/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odanyliu <odanyliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 19:51:11 by vaiz              #+#    #+#             */
/*   Updated: 2026/04/02 11:38:21 by odanyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	this->_name = "DefaultFragTrap"; 
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap default constructor" << std::endl;
}

FragTrap::FragTrap(std::string name)
{
	this->_name = name;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap constructor" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	this->_name = other.getName();
	this->_hitPoints = other.getHitPoints();
	this->_energyPoints = other.getEnergyPoints();
	this->_attackDamage = other.getAttackDamage();
	std::cout << "FragTrap Copy assignment operator " << std::endl;
	return (*this);
}

FragTrap::FragTrap(FragTrap &other)
{
	this->_name = other.getName();
	this->_hitPoints = other.getHitPoints();
	this->_energyPoints = other.getEnergyPoints();
	this->_attackDamage = other.getAttackDamage();
	std::cout << "FragTrap copy constructor" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap requests a positive high five! ✋" << std::endl;	
}