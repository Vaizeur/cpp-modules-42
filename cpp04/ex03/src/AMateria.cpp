/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaiz <vaiz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 11:33:11 by odanyliu          #+#    #+#             */
/*   Updated: 2026/04/23 12:16:13 by vaiz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AMateria.hpp"

AMateria::AMateria() : _type("no_type") {}

AMateria::AMateria(const AMateria &other) : _type(other._type) {}

AMateria& AMateria::operator=(const AMateria &other)
{
	if (this == &other)
		return (*this);
	this->_type = other._type;    
	return (*this);
}

AMateria::AMateria(std::string const &type) : _type(type) { }

std::string	const & AMateria::getType() const {
	return _type;
}

void AMateria::use(ICharacter& target) {
	(void) target;
}

AMateria::~AMateria(){}