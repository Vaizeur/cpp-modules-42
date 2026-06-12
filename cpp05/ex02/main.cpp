/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odanyliu <odanyliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 11:29:28 by odanyliu          #+#    #+#             */
/*   Updated: 2026/06/12 10:30:49 by odanyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	std::srand(std::time(NULL));
	std::cout << "\n========== BUREAUCRATS ==========\n" << std::endl;

	Bureaucrat boss("Boss", 1);
	Bureaucrat employee("Employee", 70);
	Bureaucrat intern("Intern", 150);

	std::cout << boss << std::endl;
	std::cout << employee << std::endl;
	std::cout << intern << std::endl;

	std::cout << "\n========== FORMS ==========\n" << std::endl;

	ShrubberyCreationForm shrub("garden");
	RobotomyRequestForm robot("Bender");
	PresidentialPardonForm pardon("Arthur Dent");

	std::cout << shrub << std::endl;
	std::cout << robot << std::endl;
	std::cout << pardon << std::endl;

	std::cout << "\n========== EXECUTE UNSIGNED ==========\n" << std::endl;

	boss.executeForm(shrub);
	boss.executeForm(robot);
	boss.executeForm(pardon);

	std::cout << "\n========== SIGNING ==========\n" << std::endl;

	intern.signForm(shrub);
	intern.signForm(robot);
	intern.signForm(pardon);

	employee.signForm(shrub);
	employee.signForm(robot);
	employee.signForm(pardon);

	boss.signForm(shrub);
	boss.signForm(robot);
	boss.signForm(pardon);

	std::cout << "\n========== EXECUTION ==========\n" << std::endl;

	employee.executeForm(shrub);
	employee.executeForm(robot);
	employee.executeForm(pardon);

	std::cout << "\n========== BOSS EXECUTION ==========\n" << std::endl;

	boss.executeForm(shrub);
	boss.executeForm(robot);
	boss.executeForm(robot);
	boss.executeForm(robot);
	boss.executeForm(pardon);

	std::cout << "\n========== DIRECT CALL ==========\n" << std::endl;

	try
	{
		shrub.execute(boss);
		robot.execute(boss);
		pardon.execute(boss);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "\n========== MARVIN TEST ==========\n" << std::endl;

	try
	{
		RobotomyRequestForm test("marvin");
		boss.signForm(test);
		Bureaucrat low("Low", 150);
		test.execute(low);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}