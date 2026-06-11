/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odanyliu <odanyliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 09:51:10 by odanyliu          #+#    #+#             */
/*   Updated: 2026/06/09 16:49:56 by odanyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("default_form"), _signed(false), _requiredSign(1), _requiredExec(1){}

Form::Form(std::string name,int requiredSign,int requiredExec) :
	_name(name),
	_signed(false)
{
	checkGrade(requiredSign);
	checkGrade(requiredExec);
	_requiredSign = requiredSign;
	_requiredExec = requiredExec;
}

Form::Form(const Form &other) {
	*this = other;
}

Form& Form::operator=(const Form &other)
{
	if (this != &other){
		_signed = other._signed;
		_requiredSign = other._requiredSign;
		_requiredExec = other._requiredExec;
	}
	return *this;
}

void Form::checkGrade(int grade)
{
	if (grade < 1)
		throw Form::GradeTooHighException();
	if (grade > 150)
		throw Form::GradeTooLowException();
}

const std::string& Form::getName() const {
	return _name;
}

bool Form::isSigned() const{
	return _signed;
}

int Form::getRequiredGradeSign() const {
	return _requiredSign;
}

int Form::getRequiredGradeExec() const {
	return _requiredExec;
}

void	Form::beSigned(Bureaucrat &bc)
{
	if (bc.getGrade() > _requiredSign)
		throw GradeTooLowException();
	_signed = true;
}

char const* Form::GradeTooHighException::what() const throw() {
	return "FormException - Grade is too high !";
}

char const* Form::GradeTooLowException::what() const throw() {
	return "FormException - Grade is too low";
}

std::ostream &operator<<(std::ostream &out, const Form &c)
{
	out << "Name : " << c.getName()
		<< " Is signed : "
		<< (c.isSigned() ? "true" : "false")
		<< " grade required to sign : " << c.getRequiredGradeSign()
		<< " grade required to exec : " << c.getRequiredGradeExec();
	return out;
}

Form::~Form(){}