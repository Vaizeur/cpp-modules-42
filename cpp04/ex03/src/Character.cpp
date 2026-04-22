/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odanyliu <odanyliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 10:50:32 by odanyliu          #+#    #+#             */
/*   Updated: 2026/04/21 11:30:42 by odanyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Character.hpp"

Character::Character(void) : _name("no_name") {
	for (size_t i = 0; i < 4; i++)
		_slot[i] = nullptr;
}

Character::Character(std::string name) : _name(name) {
	for (size_t i = 0; i < 4; i++)
		_slot[i] = nullptr;
}

Character::Character(Character &other)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (this->_slot[i])
			delete this->_slot[i];
		this->_slot[i] = nullptr;		
		if (other._slot[i])
			this->_slot[i] = (other._slot[i])->clone();
	}
	this->_name = other._name;
}

Character& Character::operator=(Character &other)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (this->_slot[i])
			delete this->_slot[i];
		if (other._slot[i])
			this->_slot[i] = (other._slot[i])->clone();
	}
	this->_name = other._name;
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
		this->_slot[idx] = nullptr;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
		return ;
	if (!this->_slot[idx])
		return ;
	this->_slot[idx]->use(target);
}