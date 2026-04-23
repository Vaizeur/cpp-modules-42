/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaiz <vaiz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 11:30:42 by odanyliu          #+#    #+#             */
/*   Updated: 2026/04/23 12:16:38 by vaiz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Ice.hpp"

Ice::Ice(void)
{
	_type = "ice";
}

Ice::Ice(const Ice &other) : AMateria(other) { }

Ice& Ice::operator=(const Ice &other)
{
	if (this == &other)
		return (*this);
	_type = other.getType(); // USELESS
	return (*this);
}

std::string const& Ice::getType() const 
{
	return (_type);
}

Ice::~Ice()
{
	// TODO : A FAIRE
}

Ice* Ice::clone() const
{
	return (new Ice());
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
