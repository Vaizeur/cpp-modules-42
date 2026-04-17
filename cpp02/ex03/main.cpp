/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odanyliu <odanyliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 18:21:47 by vaiz              #+#    #+#             */
/*   Updated: 2026/04/17 15:11:07 by odanyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

bool	bsp(Point const a, Point const b, Point const c, Point const point);

int	main(void)
{
	Point A(0,0);
	Point B(10,0);
	Point C(0,10);
	Point P(2,2);
	if (bsp(A,B,C,P))
	{
		std::cout << "[NICE] Inside" << std::endl;
		return (0);
	}
	std::cout << "[RIP] Not Inside" << std::endl;
	return (0);
}