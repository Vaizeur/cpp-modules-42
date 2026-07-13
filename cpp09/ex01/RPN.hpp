#ifndef RPN_HPP
# define RPN_HPP
# include <string>
# include <iostream>
# include <stack>
# include <limits.h>

class RPN
{
	private:
		RPN();
		std::string		_expr;
		void	handleOperator(std::stack<int> &stack, char op);
		bool	isOperator(char c);
		void	checkOverflow(long long res);
	public:
		RPN(const RPN &other);
		RPN(const std::string &expr);
		RPN& operator=(const RPN &other);
		void	calcul();
		~RPN();
		
		class OperatorException : public std::exception
		{
			private :
				std::string _message;
			public :
				OperatorException(const std::string &message);
				virtual ~OperatorException() throw();
				virtual const char* what() const throw();
		};
};

#endif