/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odanyliu <odanyliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 13:31:54 by odanyliu          #+#    #+#             */
/*   Updated: 2026/04/02 14:43:08 by odanyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : _type("undefined") {
	std::cout << "Animal Constructor" << std::endl;
}

Animal::Animal(Animal &other)
{
	this->_type = other._type;
	std::cout << "Animal copy constructor" << std::endl;
}
Animal& Animal::operator=(Animal &other)
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
