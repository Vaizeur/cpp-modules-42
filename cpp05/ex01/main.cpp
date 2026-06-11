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

int main()
{
	std::cout << "========== VALID OBJECTS ==========\n";
	try
	{
		Bureaucrat boss(1, "Boss");
		Bureaucrat employee( 75,"Employee");
		Bureaucrat intern(150,"intern");

		Form contract("Contract", 100, 50);
		Form secret("SecretForm", 10, 5);

		std::cout << boss << std::endl;
		std::cout << employee << std::endl;
		std::cout << intern << std::endl;

		std::cout << contract << std::endl;
		std::cout << secret << std::endl;

		std::cout << "\n========== SIGN SUCCESS ==========\n";
		employee.signForm(contract);
		std::cout << contract << std::endl;

		std::cout << "\n========== SIGN FAILURE ==========\n";
		intern.signForm(secret);
		std::cout << secret << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Unexpected exception: " << e.what() << std::endl;
	}

	std::cout << "\n========== INVALID FORM (HIGH) ==========\n";
	try
	{
		Form invalid("InvalidHigh", 0, 50);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n========== INVALID FORM (LOW) ==========\n";
	try
	{
		Form invalid("InvalidLow", 151, 50);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n========== INVALID EXEC GRADE ==========\n";
	try
	{
		Form invalid("InvalidExec", 50, 151);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
