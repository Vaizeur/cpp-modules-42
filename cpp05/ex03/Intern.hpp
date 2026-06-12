#ifndef INTERN_HPP
# define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern &other);
		Intern& operator=(const Intern &other);

		std::string cleanName(const std::string &name);

		AForm *makeForm(const std::string &form,const std::string target);
		AForm *createRobotomyRequestForm(const std::string &target);
		AForm *createPresidentialPardonForm(const std::string &target);
		AForm *createShrubberyCreationForm(const std::string &target);
		~Intern();
};



#endif