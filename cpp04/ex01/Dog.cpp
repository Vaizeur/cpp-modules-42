/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odanyliu <odanyliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 13:31:54 by odanyliu          #+#    #+#             */
/*   Updated: 2026/05/12 11:07:58 by odanyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) {
	this->_type = "Dog";
	this->_brain = new Brain();
	std::cout << "Dog Constructor" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
	this->_brain = new Brain(*other._brain);
	this->_type = other._type;
	std::cout << "Dog copy constructor" << std::endl;
}
Dog& Dog::operator=(const Dog &other)
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

void Dog::addIdea(std::string &value)
{
	_brain->addIdea(value);
}

void Dog::printIdea() const {
	_brain->printIdea();
}