/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odanyliu <odanyliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 10:41:20 by odanyliu          #+#    #+#             */
/*   Updated: 2026/03/30 16:35:02 by odanyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(0), _y(0) {}

Point::Point(float x, float y) : _x(x), _y(y) {}

Point::Point(const Point &other) : _x(other._x), _y(other._y) {}

Point &Point::operator=(const Point &other)
{
	(void) other;
	return (*this);
}

Point::~Point(void) {}

Fixed	Point::getX() const { return (this->_x); }

Fixed	Point::getY() const { return (this->_y); }