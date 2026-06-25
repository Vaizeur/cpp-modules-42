/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odanyliu <odanyliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 09:48:32 by odanyliu          #+#    #+#             */
/*   Updated: 2026/06/25 10:40:34 by odanyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP
# include <string>
# include "Bureaucrat.hpp"
# include <cstdlib>

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_signed;
		int					_requiredSign;
		int					_requiredExec;
		static	void		checkGrade(int  grade);
	public:
		AForm();
		AForm(std::string name, int requiredSign,int requiredExec);
		AForm(const AForm &other);
		AForm& operator=(const AForm &other);
		virtual ~AForm();

		const std::string&	getName() const;
		bool				isSigned() const;
		int					getRequiredGradeSign() const;
		int					getRequiredGradeExec() const;
		
		void				beSigned(Bureaucrat &bc);
		virtual void		execute(Bureaucrat const & executor) const = 0;
		void				canExecute(const Bureaucrat& executor) const;
		void				setSigned();
		
		class GradeTooHighException : public std::exception {
			char const* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			char const* what() const throw();
		};
		class FormAlreadySigned : public std::exception {
			char const* what() const throw();
		};
		class ExecuteException : public std::exception {
			private :
				std::string _message;
			public :
				ExecuteException(const std::string &message);
				virtual ~ExecuteException() throw();
				virtual const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const AForm &c);

#endif