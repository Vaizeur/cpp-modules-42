#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", 72, 45),
	  _target("unknow")
{}
RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("RobotomyRequestForm", 72, 45),
	  _target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm("RobotomyRequestForm", 72, 45)
{
	*this = other;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other){
		if (other.isSigned())
			this->setSigned();
		_target = other._target;
	}
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	canExecute(executor);
	std::time_t t = std::time(0);
	if (t % 2 == 0)
		std::cout << _target << " robotomy failed" << std::endl;
	else
		std::cout << _target << " has been robotomized" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(){}

