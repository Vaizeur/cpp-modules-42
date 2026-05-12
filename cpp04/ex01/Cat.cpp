/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odanyliu <odanyliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 13:31:54 by odanyliu          #+#    #+#             */
/*   Updated: 2026/05/12 11:08:02 by odanyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) {
	this->_type = "Cat";
	this->_brain = new Brain();
	std::cout << "Cat Constructor" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	this->_brain = new Brain(*other._brain);
	this->_type = other._type;
	std::cout << "Cat copy constructor" << std::endl;
}
Cat& Cat::operator=(const Cat &other)
{
	std::cout << "Cat assignement operator" << std::endl;
	if (this == &other)
		return (*this);
	this->_type = other._type;
	delete this->_brain;
	// DeepCopy
	this->_brain = new Brain(*other._brain);
	return (*this);
}

Cat::~Cat() {
	std::cout << "Cat destructor" << std::endl;
	delete _brain;
}

void Cat::makeSound() const
{
	std::cout << "Miaou" << std::endl;
}

void Cat::addIdea(std::string &value)
{
	_brain->addIdea(value);
}

void Cat::printIdea() const {
	_brain->printIdea();
}
