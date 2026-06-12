#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137),
	  _target("unknow")
{}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShrubberyCreationForm", 145, 137),
	  _target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm("ShrubberyCreationForm", 145, 137)
{
	*this = other;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
		_target = other._target;
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	canExecute(executor);
	std::ofstream file((_target + "_shrubbery").c_str());

	if (!file.is_open())
		throw ExecuteException("Can't open shrubbery file");

	file << "       _-_" << std::endl;
	file << "    /~~   ~~\\" << std::endl;
	file << " /~~         ~~\\" << std::endl;
	file << "{               }" << std::endl;
	file << " \\  _-     -_  /" << std::endl;
	file << "   ~  \\\\ //  ~" << std::endl;
	file << "_- -   | | _- _" << std::endl;
	file << "  _ -  | |   -_" << std::endl;
	file << "      // \\\\" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

