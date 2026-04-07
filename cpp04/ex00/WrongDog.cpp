/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odanyliu <odanyliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 13:31:54 by odanyliu          #+#    #+#             */
/*   Updated: 2026/04/07 12:54:51 by odanyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongDog.hpp"

WrongDog::WrongDog(void) {
	this->_type = "WrongDog";
	std::cout << "WrongDog Constructor" << std::endl;
}

WrongDog::WrongDog(WrongDog &other)
{
	this->_type = other._type;
	std::cout << "WrongDog copy constructor" << std::endl;
}
WrongDog& WrongDog::operator=(WrongDog &other)
{
	std::cout << "WrongDog assignement operator" << std::endl;
	if (this == &other)
		return (*this);
	this->_type = other._type;
	return (*this);
}

WrongDog::~WrongDog() {
	std::cout << "WrongDog destructor" << std::endl;
}

void WrongDog::makeSound() const
{
	std::cout << "Wrong wouf" << std::endl;
}
