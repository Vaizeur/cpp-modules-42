#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main(void)
{
	std::srand(std::time(NULL));
	std::cout << "\n========== INTERN TEST ==========\n" << std::endl;

	Intern someRandomIntern;

	AForm* shrub = someRandomIntern.makeForm(
		"shrubbery creation",
		"home"
	);

	AForm* robot = someRandomIntern.makeForm(
		"robotomy request",
		"Bender"
	);

	AForm* pardon = someRandomIntern.makeForm(
		"presidential pardon",
		"Arthur Dent"
	);

	AForm* invalid = someRandomIntern.makeForm(
		"coffee request",
		"Student"
	);

	std::cout << "\n========== BUREAUCRATS ==========\n" << std::endl;

	Bureaucrat boss("Boss", 1);
	Bureaucrat employee("Employee", 70);

	std::cout << "\n========== SHRUBBERY ==========\n" << std::endl;

	if (shrub)
	{
		employee.signForm(*shrub);
		employee.executeForm(*shrub);
	}

	std::cout << "\n========== ROBOTOMY ==========\n" << std::endl;

	if (robot)
	{
		employee.signForm(*robot);

		boss.executeForm(*robot);
		boss.executeForm(*robot);
		boss.executeForm(*robot);
	}

	std::cout << "\n========== PARDON ==========\n" << std::endl;

	if (pardon)
	{
		boss.signForm(*pardon);
		boss.executeForm(*pardon);
	}

	std::cout << "\n========== INVALID FORM ==========\n" << std::endl;

	if (!invalid)
		std::cout << "Invalid form correctly rejected." << std::endl;

	delete shrub;
	delete robot;
	delete pardon;
	delete invalid;

	return (0);
}