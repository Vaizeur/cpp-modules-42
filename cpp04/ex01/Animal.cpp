/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odanyliu <odanyliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 13:31:54 by odanyliu          #+#    #+#             */
/*   Updated: 2026/05/12 11:08:18 by odanyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : _type("undefined") {
	std::cout << "Animal Constructor" << std::endl;
}

Animal::Animal(const Animal &other)
{
	this->_type = other._type;
	std::cout << "Animal copy constructor" << std::endl;
}
Animal& Animal::operator=(const Animal &other)
{
	std::cout << "Animal assignement operator" << std::endl;
	if (this == &other)
		return (*this);
	this->_type = other._type;
	return (*this);
}

Animal::~Animal() {
	std::cout << "Animal destructor" << std::endl;
}

void Animal::makeSound() const
{
    std::cout << "Some animal sound" << std::endl;
}

std::string Animal::getType(void) const
{
    return this->_type;
}

void Animal::addIdea(std::string &value)
{
	(void) value;		
}

void Animal::printIdea() const { }

