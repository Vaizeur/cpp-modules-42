/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odanyliu <odanyliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 13:31:54 by odanyliu          #+#    #+#             */
/*   Updated: 2026/04/10 09:58:04 by odanyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) {
	this->_type = "Dog";
	this->_brain = new Brain();
	std::cout << "Dog Constructor" << std::endl;
}

Dog::Dog(Dog &other)
{
	this->_brain = new Brain(*other._brain);
	this->_type = other._type;
	std::cout << "Dog copy constructor" << std::endl;
}
Dog& Dog::operator=(Dog &other)
{
	std::cout << "Dog assignement operator" << std::endl;
	if (this == &other)
		return (*this);
	this->_type = other._type;
	delete this->_brain;
	this->_brain = new Brain(*other._brain);
	return (*this);
}

Dog::~Dog() {
	std::cout << "Dog destructor" << std::endl;
	delete _brain;
}

void Dog::makeSound() const
{
	std::cout << "Wouf" << std::endl;
}
