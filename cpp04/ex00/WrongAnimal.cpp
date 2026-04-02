/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odanyliu <odanyliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 13:31:54 by odanyliu          #+#    #+#             */
/*   Updated: 2026/04/02 15:07:46 by odanyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("undefined") {
	std::cout << "WrongAnimal Constructor" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal &other)
{
	this->_type = other._type;
	std::cout << "WrongAnimal copy constructor" << std::endl;
}
WrongAnimal& WrongAnimal::operator=(WrongAnimal &other)
{
	std::cout << "WrongAnimal assignement operator" << std::endl;
	if (this == &other)
		return (*this);
	this->_type = other._type;
	return (*this);
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor" << std::endl;
}

void WrongAnimal::makeSound() const
{
    std::cout << "Some WrongAnimal sound" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
    return this->_type;
}
