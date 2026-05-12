/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odanyliu <odanyliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 13:31:54 by odanyliu          #+#    #+#             */
/*   Updated: 2026/05/12 11:12:24 by odanyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void) : _type("undefined") {
	std::cout << "Animal Constructor" << std::endl;
}

AAnimal::AAnimal(const AAnimal &other)
{
	this->_type = other._type;
	std::cout << "Animal copy constructor" << std::endl;
}
AAnimal& AAnimal::operator=(const AAnimal &other)
{
	std::cout << "Animal assignement operator" << std::endl;
	if (this == &other)
		return (*this);
	this->_type = other._type;
	return (*this);
}

AAnimal::~AAnimal() {
	std::cout << "Animal destructor" << std::endl;
}

void AAnimal::makeSound() const
{
    std::cout << "Some animal sound" << std::endl;
}

std::string AAnimal::getType(void) const
{
    return this->_type;
}

void AAnimal::addIdea(std::string &value) {
	(void) value;		
}

void AAnimal::printIdea() const { }