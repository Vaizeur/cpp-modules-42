/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaiz <vaiz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 10:50:32 by odanyliu          #+#    #+#             */
/*   Updated: 2026/04/23 15:01:19 by vaiz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Character.hpp"

Character::Character(void) : _name("no_name") {
	for (size_t i = 0; i < 4; i++)
		_slot[i] = NULL;
}

Character::Character(std::string name) : _name(name) {
	for (size_t i = 0; i < 4; i++)
		_slot[i] = NULL;
}

Character::Character(const Character &other)
{
	for (size_t i = 0; i < 4; i++)
	{
		this->_slot[i] = NULL;		
		if (other._slot[i])
			this->_slot[i] = (other._slot[i])->clone();
	}
	this->_name = other._name;
}

Character& Character::operator=(const Character &other)
{
	if (this == &other)
		return (*this);
	for (size_t i = 0; i < 4; i++)
	{
		if (this->_slot[i])
			delete this->_slot[i];
		if (other._slot[i])
			this->_slot[i] = (other._slot[i])->clone();
	}
	this->_name = other._name;
	return (*this);
}

Character::~Character()
{
	for (size_t i = 0; i < 4; i++)
	{
		if (this->_slot[i])
			delete this->_slot[i];
	}
}

void Character::equip(AMateria* m)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (!this->_slot[i])
		{
			this->_slot[i] = m;	
			return ;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
		return ;	
	if (this->_slot[idx])
		this->_slot[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
		return ;
	if (!this->_slot[idx])
		return ;
	(this->_slot[idx])->use(target);
}

std::string const&Character::getName() const
{
	return (this->_name);
}