/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odanyliu <odanyliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 19:51:11 by vaiz              #+#    #+#             */
/*   Updated: 2026/04/01 11:31:14 by odanyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : 
	_name("NoName") , 
	_hitPoints(10) , 
	_energyPoints(10) , 
	_attackDamage(0)
{
	std::cout << "ClapTrap default constructor" << std::endl;
}

ClapTrap::ClapTrap(std::string name) :
	_name(name) , 
	_hitPoints(10) , 
	_energyPoints(10) , 
	_attackDamage(0)
{ 
	std::cout << "ClapTrap constructor" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) :
 _name(other._name) , 
 _hitPoints(other._hitPoints) ,
 _energyPoints(other._energyPoints) ,
 _attackDamage(other._attackDamage)
{ 
	std::cout << "ClapTrap copy constructor" << std::endl;	
}

ClapTrap	 &ClapTrap::operator=(const ClapTrap &other)
{
	this->_name = other.getName();
	this->_hitPoints = other.getHitPoints();
	this->_energyPoints = other.getEnergyPoints();
	this->_attackDamage = other.getAttackDamage();
	
	std::cout << "ClapTrap Copy assignment operator " << std::endl;
	return (*this);
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

void ClapTrap::setName(std::string name)
{
	this->_name = name;
}

void ClapTrap::setHitPoints(unsigned int amount)
{
	this->_hitPoints = amount;
}

void ClapTrap::setEnergyPoints(unsigned int amount)
{
	this->_energyPoints = amount;
}

void ClapTrap::setAttackDamage(unsigned int amount)
{
	this->_attackDamage = amount;
}

void ClapTrap::attack(const std::string& target)
{
	if (!this->check())
		return ;	
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing "<< this->_attackDamage << " points of damage!" << std::endl;
	this->_energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->_name << " take " << amount << " damage !" << std::endl;
	this->_hitPoints -= amount;	
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!this->check())
		return ;
	std::cout << "ClapTrap " << this->_name << " be repaired " << amount << " amount" << std::endl;
	this->_hitPoints += amount;
	this->_energyPoints--;
}

bool ClapTrap::check(void)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " has no more hitpoint !" << std::endl;
		return (false);
	}
	if (this->_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " has no more energy !" << std::endl;
		return (false);
	}
	return (true);
}
