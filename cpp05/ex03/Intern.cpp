#include "Intern.hpp"

Intern::Intern(){}

Intern::Intern(const Intern &other){
	(void) other;
}

Intern&	Intern::operator=(const Intern &other){
	(void) other;
	return *this;
}

Intern::~Intern(){}


AForm *Intern::createRobotomyRequestForm(const std::string &target) {
	return (new RobotomyRequestForm(target));
}

AForm *Intern::createPresidentialPardonForm(const std::string &target) {
	return (new PresidentialPardonForm(target));
}

AForm *Intern::createShrubberyCreationForm(const std::string &target) {
	return (new ShrubberyCreationForm(target));
}

std::string Intern::cleanName(const std::string &name)
{
	std::string res;

	for (std::size_t i = 0; i < name.length(); ++i)
	{
		if (!std::isspace(name[i]))
			res += std::tolower(name[i]);
	}
	return res;
}

AForm* Intern::makeForm(const std::string &form,const std::string target) {
	std::pair<std::string, AForm* (Intern::*)(const std::string &target)> pair[3] = {
		std::make_pair("robotomyrequest",&Intern::createRobotomyRequestForm),
		std::make_pair("presidentialpardon",&Intern::createPresidentialPardonForm),
		std::make_pair("shrubberycreation",&Intern::createShrubberyCreationForm),
	};
	std::string cleanFormName = cleanName(form);
	for (size_t i = 0; i < 3; i++)
	{
		if (cleanFormName == pair[i].first)
		{
			std::cout << "Intern creates " << form << std::endl;
			return (this->*pair[i].second)(target);
		}
	}
	std::cout << "Intern couldn't create `" << form << "`" << std::endl;
	return (NULL);
}