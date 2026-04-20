/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odanyliu <odanyliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 10:41:23 by odanyliu          #+#    #+#             */
/*   Updated: 2026/04/20 10:35:13 by odanyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP
# include <iostream>
# include "Fixed.hpp"

class Point
{
    private :
        Fixed const _x; 
        Fixed const _y; 
    public:
        Point(void);
        Point(float x, float y);
        Point(const Point& other);
        Point &operator=(const Point &other);
        ~Point();
        Fixed getX() const;
        Fixed getY() const;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif

