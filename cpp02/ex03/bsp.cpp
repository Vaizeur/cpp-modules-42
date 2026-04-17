/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odanyliu <odanyliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 11:31:46 by odanyliu          #+#    #+#             */
/*   Updated: 2026/04/17 15:12:05 by odanyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static float calcul_sign(Point const p1, Point const p2, Point const p3)
{
    return (p1.getX().toFloat() - p3.getX().toFloat()) *
		(p2.getY().toFloat() - p3.getY().toFloat()) -
        (p2.getX().toFloat() - p3.getX().toFloat()) *
        (p1.getY().toFloat() - p3.getY().toFloat());
}
bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    bool b1 = calcul_sign(point, a, b) < 0;
    bool b2 = calcul_sign(point, b, c) < 0;
    bool b3 = calcul_sign(point, c, a) < 0;
    return (b1 && b2 && b3);
}
