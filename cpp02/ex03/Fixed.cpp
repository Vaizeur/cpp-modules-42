/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odanyliu <odanyliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 18:20:25 by vaiz              #+#    #+#             */
/*   Updated: 2026/04/21 10:24:04 by odanyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0) , _fractionalB(8)
{
}

Fixed::Fixed(const int value) : _fractionalB(8)
{
	_value = value << _fractionalB;
}

Fixed::Fixed(const float value) : _fractionalB(8)
{
	_value = roundf(value * (1 << _fractionalB));
}

Fixed::Fixed(const Fixed &other)
{
	this->_value = other.getRawBits();
	this->_fractionalB = other.getFractionalB();
}

std::ostream &operator<<(std::ostream &out, const Fixed &c)
{
	out << c.toFloat();
	return out;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	if (this == &other)
		return (*this);
	this->_value = other.getRawBits();
	this->_fractionalB = other.getFractionalB();
	return (*this);
}

Fixed::~Fixed(void)
{
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

bool 	Fixed::operator==(const Fixed& other) const
{
	return (this->getRawBits() == other.getRawBits());
}

bool 	Fixed::operator<(const Fixed& other) const
{
	return (this->getRawBits() < other.getRawBits());
}

bool 	Fixed::operator>(const Fixed& other) const
{
	return (this->getRawBits() > other.getRawBits());
}

bool 	Fixed::operator<=(const Fixed& other) const
{
	return (this->getRawBits() <= other.getRawBits());
}

bool 	Fixed::operator>=(const Fixed& other) const
{
	return (this->getRawBits() >= other.getRawBits());
}

bool 	Fixed::operator!=(const Fixed& other) const
{
	return (this->getRawBits() != other.getRawBits());
}

Fixed	Fixed::operator+(const Fixed& other)
{
	this->_value += other.getRawBits();
	return (*this);
}

Fixed	Fixed::operator-(const Fixed& other)
{
	this->_value -= other.getRawBits();
	return (*this);
}

Fixed	Fixed::operator*(const Fixed& other)
{
	float	res;

	res = this->toFloat() * other.toFloat();
	this->_value = roundf(res * (1 << this->getFractionalB()));
	return (*this);
}

Fixed	Fixed::operator/(const Fixed& other)
{
	float	res;

	res = this->toFloat() / other.toFloat();
	this->_value = roundf(res * (1 << this->getFractionalB()));
	return (*this);
}

//++i
Fixed Fixed::operator++()
{
	this->_value++;
	return (*this);
}

// i++
Fixed Fixed::operator++(int)
{
	Fixed tmp(this->toFloat());
	
	this->_value++;
	return (tmp);
}

//--i
Fixed Fixed::operator--()
{
	this->_value--;
	return (*this);
}

// i--
Fixed Fixed::operator--(int)
{
	Fixed tmp(this->toFloat());
	
	this->_value--;
	return (tmp);
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b ? a : b);
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	return (a > b ? b : a);
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b ? a : b);
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a > b ? b : a);
}