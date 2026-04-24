/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odanyliu <odanyliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 10:04:16 by odanyliu          #+#    #+#             */
/*   Updated: 2026/04/24 11:41:19 by odanyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Constructor

Bureaucrat::Bureaucrat(void) : _grade(150), _name("no_name") { }

Bureaucrat::Bureaucrat(int grade) : _name("no_name")
{ 
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(int grade, std::string name) : _name(name)
{ 
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(std::string name) : _grade(150) , _name(name) { }

Bureaucrat::Bureaucrat(const Bureaucrat &other) :  _grade(other._grade), _name(other._name)
{
	std::cout << "Copy constructor called" << std::endl;
	return ;
}


Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this == &other)
		return (*this);
	this->_grade = other._grade;	
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

std::string Bureaucrat::getName() const
{
	return _name;
}

int	Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::incrementGrade()
{
	if (this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &c)
{
	out << c.getName() << " bureaucrat grade " << c.getGrade();
	return out;
}

char const* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "GradeTooHigh Exception";
}

char const* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "GradeTooLow Exception";
}