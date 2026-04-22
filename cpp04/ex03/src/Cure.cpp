/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odanyliu <odanyliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 11:30:42 by odanyliu          #+#    #+#             */
/*   Updated: 2026/04/21 13:11:22 by odanyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cure.hpp"

Cure::Cure(void)
{
	_type = "cure";
}

Cure::Cure(Cure &other)  : AMateria(other) {
	
}

Cure& Cure::operator=(Cure &other)
{
	if (this == &other)
		return (*this);
	_type = other._type; // USELESS
	return (*this);
}

std::string const& Cure::getType() const 
{
	return (_type);
}

Cure::~Cure()
{
	// TODO : A FAIRE
}

Cure* Cure::clone() const
{
	return (new Cure());
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
