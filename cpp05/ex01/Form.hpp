/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odanyliu <odanyliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 09:48:32 by odanyliu          #+#    #+#             */
/*   Updated: 2026/06/09 16:38:37 by odanyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_signed;
		int					_requiredSign;
		int					_requiredExec;
		static	void		checkGrade(int  grade);
	public:
		Form();
		Form(std::string name, int requiredSign,int requiredExec);
		Form(const Form &other);
		Form& operator=(const Form &other);
		~Form();

		const std::string&	getName() const;
		bool				isSigned() const;
		int					getRequiredGradeSign() const;
		int					getRequiredGradeExec() const;
		
		void				beSigned(Bureaucrat &bc);
		
		class GradeTooHighException : public std::exception 
		{
			char const* what() const throw();		
		};
		
		class GradeTooLowException : public std::exception 
		{
    		char const* what() const throw();		
		};
};

std::ostream &operator<<(std::ostream &out, const Form &c);

#endif