/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odanyliu <odanyliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 10:04:24 by odanyliu          #+#    #+#             */
/*   Updated: 2026/06/09 10:16:26 by odanyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		int					_grade;
		const std::string 	_name;
	public:
		Bureaucrat(void);
		Bureaucrat(int grade);
		Bureaucrat(int grade, std::string name);
		Bureaucrat(std::string name);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat &operator=(const Bureaucrat &other);
		
		std::string getName() const;
		int getGrade() const;

		void incrementGrade();
		void decrementGrade();
		void signForm(AForm &form);
		void executeForm(AForm const & form) const;

		~Bureaucrat();

		class GradeTooHighException : public std::exception 
		{
    		char const* what() const throw();		
		};
		
		class GradeTooLowException : public std::exception 
		{
    		char const* what() const throw();		
		};
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &c);

#endif