/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odanyliu <odanyliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 13:31:54 by odanyliu          #+#    #+#             */
/*   Updated: 2026/04/02 15:12:59 by odanyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) {
	this->_type = "WrongCat";
	std::cout << "WrongCat Constructor" << std::endl;
}

WrongCat::WrongCat(WrongCat &other)
{
	this->_type = other._type;
	std::cout << "WrongCat copy constructor" << std::endl;
}
WrongCat& WrongCat::operator=(WrongCat &other)
{
	std::cout << "WrongCat assignement operator" << std::endl;
	if (this == &other)
		return (*this);
	this->_type = other._type;
	return (*this);
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "Wrong Miaou" << std::endl;
}
