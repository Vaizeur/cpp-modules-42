/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odanyliu <odanyliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 11:29:28 by odanyliu          #+#    #+#             */
/*   Updated: 2026/04/24 11:40:03 by odanyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	try {
		Bureaucrat crat(151);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	try
	{
		Bureaucrat crat(12, "bob");
		std::cout << crat << std::endl;
		for (size_t i = 0; i < 150; i++)
		{
			std::cout << crat << std::endl;
			crat.incrementGrade();
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	
	return 0;
}
