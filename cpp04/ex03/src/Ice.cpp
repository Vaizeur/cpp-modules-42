/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odanyliu <odanyliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 11:30:42 by odanyliu          #+#    #+#             */
/*   Updated: 2026/04/20 11:40:41 by odanyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Ice.hpp"

Ice::Ice(void) {
	_type = "ice";
}

Ice::Ice(Ice &other) {
	_type = other.getType();
}

Ice& Ice::operator=(Ice &other)
{
	if (this == &other)
		return (*this);
	_type = other.getType();
	return (*this);
}

std::string const& Ice::getType() const 
{
	return (_type);
}

Ice::~Ice() {
	// TODO : A FAIRE
}

Ice* Ice::clone() const{
	return (new Ice());
}
