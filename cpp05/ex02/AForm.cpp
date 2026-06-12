/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odanyliu <odanyliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 09:51:10 by odanyliu          #+#    #+#             */
/*   Updated: 2026/06/12 09:27:42 by odanyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("default_form"), _signed(false), _requiredSign(1), _requiredExec(1){}

AForm::AForm(std::string name,int requiredSign,int requiredExec) :
	_name(name),
	_signed(false)
{
	checkGrade(requiredSign);
	checkGrade(requiredExec);
	_requiredSign = requiredSign;
	_requiredExec = requiredExec;
}

AForm::AForm(const AForm &other) {
	*this = other;
}

AForm& AForm::operator=(const AForm &other)
{
	if (this != &other){
		_signed = other._signed;
		_requiredSign = other._requiredSign;
		_requiredExec = other._requiredExec;
	}
	return *this;
}

void AForm::checkGrade(int grade)
{
	if (grade < 1)
		throw AForm::GradeTooHighException();
	if (grade > 150)
		throw AForm::GradeTooLowException();
}

const std::string& AForm::getName() const {
	return _name;
}

bool AForm::isSigned() const{
	return _signed;
}

void AForm::setSigned(){
	_signed = true;
}

int AForm::getRequiredGradeSign() const {
	return _requiredSign;
}

int AForm::getRequiredGradeExec() const {
	return _requiredExec;
}

void	AForm::beSigned(Bureaucrat &bc)
{
	if (bc.getGrade() > _requiredSign)
		throw GradeTooLowException();
	if (_signed)
		throw FormAlreadySigned();	
	_signed = true;
}

char const* AForm::GradeTooHighException::what() const throw() {
	return "AFormException - Grade is too high !";
}

char const* AForm::GradeTooLowException::what() const throw() {
	return "AFormException - Grade is too low";
}

char const* AForm::FormAlreadySigned::what() const throw(){
	return "AFormException - Form is already signed";
}

AForm::ExecuteException::ExecuteException(const std::string &message) : _message(message){}

AForm::ExecuteException::~ExecuteException() throw() { }

const char* AForm::ExecuteException::what() const throw() {
	return _message.c_str();
}

std::ostream &operator<<(std::ostream &out, const AForm &c)
{
	out << "Name : " << c.getName()
		<< " Is signed : "
		<< (c.isSigned() ? "true" : "false")
		<< " grade required to sign : " << c.getRequiredGradeSign()
		<< " grade required to exec : " << c.getRequiredGradeExec();
	return out;
}

void		AForm::execute(Bureaucrat const & executor) const
{
	(void) executor;
}

void		AForm::canExecute(const Bureaucrat& executor) const
{
	if (!_signed)
		throw ExecuteException("Form is not signed");
	if (executor.getGrade() > _requiredExec)
		throw ExecuteException("Grade too low to execute form");
}

AForm::~AForm(){}