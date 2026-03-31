/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odanyliu <odanyliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 10:41:23 by odanyliu          #+#    #+#             */
/*   Updated: 2026/03/30 16:32:26 by odanyliu         ###   ########.fr       */
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

#endif

