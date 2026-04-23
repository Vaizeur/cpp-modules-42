/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaiz <vaiz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 13:26:31 by odanyliu          #+#    #+#             */
/*   Updated: 2026/04/23 15:02:15 by vaiz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MateriaSource.hpp"

MateriaSource::MateriaSource() : _idx(0)
{
	for (size_t i = 0; i < 4; i++)
		this->_learn[i] = NULL;
}

MateriaSource::~MateriaSource()
{
	for (size_t i = 0; i < 4; i++)
	{
		if (this->_learn[i])
			delete (this->_learn[i]);
	}
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	this->_idx = other._idx;
	for (size_t i = 0; i < 4; i++)
	{
		this->_learn[i] = NULL;
		if (other._learn[i])
			this->_learn[i] = (other._learn[i])->clone();
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource &other)
{
	if (this == &other)
		return (*this);	
	this->_idx = other._idx;
	for (size_t i = 0; i < 4; i++)
	{
		if (this->_learn[i])
			delete this->_learn[i];	
		this->_learn[i] = NULL;
		if (other._learn[i])
			this->_learn[i] = (other._learn[i])->clone();
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria* materia)
{
	if (this->_idx > 3)
		return ;
	this->_learn[this->_idx] = materia;
	this->_idx++;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (size_t i = 0; i < this->_idx; i++)
	{
		if (this->_learn[i]->getType() == type)
			return (this->_learn[i]->clone());		
	}
	return (NULL);
}