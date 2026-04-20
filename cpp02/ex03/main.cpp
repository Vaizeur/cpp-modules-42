/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odanyliu <odanyliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 18:21:47 by vaiz              #+#    #+#             */
/*   Updated: 2026/04/20 10:59:01 by odanyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>
#include <iostream>
#include "Point.hpp"


static void bsp_test(Point A, Point B, Point C, Point P)
{
	if (bsp(A, B, C, P))
		std::cout << "[YES] Inside  : (" << P.getX().toFloat() << ", " << P.getY().toFloat() << ")" << std::endl;
	else
		std::cout << "[NOP] Outside : (" << P.getX().toFloat() << ", " << P.getY().toFloat() << ")" << std::endl;
}

int	main(void)
{
	Point A(0,0);
	Point B(10,0);
	Point C(0,10);

	// INSIDE
	bsp_test(A,B,C, Point(2,2));
	bsp_test(A,B,C, Point(5,1)); 
	bsp_test(A,B,C, Point(1,1));

	// OUTSIDE
	bsp_test(A,B,C, Point(10,10));
	bsp_test(A,B,C, Point(-1,2));
	bsp_test(A,B,C, Point(5,6));

	// VERTEX
	bsp_test(A,B,C, Point(0,0));
	bsp_test(A,B,C, Point(10,0));
	bsp_test(A,B,C, Point(0,10));
	bsp_test(A,B,C, Point(5,0));
	bsp_test(A,B,C, Point(0,5));
	bsp_test(A,B,C, Point(5,5));
	return (0);
}