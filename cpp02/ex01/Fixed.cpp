/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaiz <vaiz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 18:20:25 by vaiz              #+#    #+#             */
/*   Updated: 2026/03/29 20:38:40 by vaiz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0) , _fractionalB(8)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : _fractionalB(8)
{
	_value = value << _fractionalB;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) : _fractionalB(8)
{
	_value = roundf(value * (1 << _fractionalB));
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

std::ostream &operator<<(std::ostream &out, const Fixed &c)
{
	out << c.toFloat();
	return out;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called " << std::endl;
	this->_value = other.getRawBits();
	this->_fractionalB = other.getFractionalB();
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::toInt(void) const 
{
	return (this->_value >> _fractionalB);
}

float Fixed::toFloat(void) const
{
	return ((float) _value / (1 << _fractionalB));
}

int		Fixed::getRawBits(void) const
{
	return (this->_value);
}

int		Fixed::getFractionalB(void) const
{
	return (this->_fractionalB);
}
