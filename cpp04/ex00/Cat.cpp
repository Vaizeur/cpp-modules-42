/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odanyliu <odanyliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 13:31:54 by odanyliu          #+#    #+#             */
/*   Updated: 2026/05/12 10:35:44 by odanyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) {
	this->_type = "Cat";
	std::cout << "Cat Constructor" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	this->_type = other._type;
	std::cout << "Cat copy constructor" << std::endl;
}
Cat& Cat::operator=(const Cat &other)
{
	std::cout << "Cat assignement operator" << std::endl;
	if (this == &other)
		return (*this);
	this->_type = other._type;
	return (*this);
}

Cat::~Cat() {
	std::cout << "Cat destructor" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Miaou" << std::endl;
}
