/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odanyliu <odanyliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 11:31:46 by odanyliu          #+#    #+#             */
/*   Updated: 2026/03/30 16:20:34 by odanyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static float calcul_w1(Point const a, Point const b, Point const c, Point const point)
{
	float ca_y = c.getY().toFloat() - a.getY().toFloat();
	float ca_x = c.getX().toFloat() - a.getX().toFloat();
	float ba_y = b.getY().toFloat() - a.getY().toFloat();
	float pa_y = point.getY().toFloat() - a.getY().toFloat();

	return ((a.getX().toFloat() * ca_y + pa_y * ca_x - point.getX().toFloat() * ca_y)
		/ (ba_y * ca_x - (b.getX().toFloat() - a.getX().toFloat()) * ca_y));
}

static float	calcul_w2(Point const a, Point const b, Point const c, Point const point, float w1)
{
	float	ca_y;
	float	ba_y;
	float	pa_y;

	ca_y = c.getY().toFloat() - a.getY().toFloat();
	ba_y = b.getY().toFloat() - a.getY().toFloat();
	pa_y = point.getY().toFloat() - a.getY().toFloat();
	return ((pa_y - w1 * ba_y) / ca_y);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	float w1 = calcul_w1(a, b, c, point);
	float w2 = calcul_w2(a, b, c, point, w1);
	return (w1 >= 0 && w2 >= 0 && (w1 + w2) <= 1);
}