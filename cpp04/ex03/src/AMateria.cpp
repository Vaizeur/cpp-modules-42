/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odanyliu <odanyliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 11:33:11 by odanyliu          #+#    #+#             */
/*   Updated: 2026/04/21 13:21:12 by odanyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AMateria.hpp"

AMateria::AMateria() : _type("no_type") {}

AMateria::AMateria(AMateria &other) : _type(other._type) {}

AMateria& AMateria::operator=(AMateria &other)
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

AMateria::~AMateria(){}