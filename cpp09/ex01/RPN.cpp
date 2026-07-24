#include "RPN.hpp"

RPN::RPN(){}

RPN::RPN(const RPN &other){
	*this = other;
}

RPN& RPN::operator=(const RPN &other){
	if (this != &other)
		_expr = other._expr;
	return *this;
}

RPN::RPN(const std::string &expr) : _expr(expr) {}

RPN::~RPN(){}


bool RPN::isOperator(char c)
{
	return c == '+' || c == '-' || c == '*' || c == '/';
}

void	RPN::checkOverflow(long long res)
{
	if (res > INT_MAX || res < INT_MIN)
		throw OperatorException("Error : Overflow detected");	
}

void	RPN::handleOperator(std::stack<int, std::list<int> > &stack, char op)
{
	if (stack.size() < 2)
		throw OperatorException("Error : Not valid stack size for operation");
	long long n1 = stack.top();
	stack.pop();
	long long n2 = stack.top();
	stack.pop();
	long long res;
	switch (op)
	{
		case '+':
			res = n2 + n1;
			break;
		case '-':
			res = n2 - n1;
			break;
		case '*':
			res = n2 * n1;
			break;
		case '/':
			if (n1 == 0)
				throw OperatorException("Error : Division by zero");
			res = n2 / n1;
			break;
	}
	checkOverflow(res);
	stack.push(res);
}

void RPN::calcul()
{
	bool	delimChecker = true;
	std::stack<int, std::list<int> >	stack;
	for (std::string::iterator it = _expr.begin(); it != _expr.end() ; it++){
		if (*it == ' '){
			delimChecker = true;
			continue;
		}
		if (std::isdigit(*it)){
			if (!delimChecker){
				std::cout << "Error : Invalid Separator" << std::endl;
				return;
			}
			stack.push(*it - '0');
			delimChecker = false;
			continue;
		}
		if (isOperator(*it)) {
			if (!delimChecker){
				std::cout << "Error : Invalid Separator" << std::endl;
				return;
			}
			try{
				handleOperator(stack, *it);
			}
			catch(const std::exception& e){
				std::cout << e.what() << std::endl;
				return ;
			}
			delimChecker = false;
			continue;
		}
		std::cout << "Error : Invalid char `"<< *it << "'" << std::endl;	
		return;
	}
	if (stack.size() != 1){
		std::cout << "Error : Does not contain a single element" << std::endl;
		return ;
	}
	std::cout << stack.top() << std::endl;
}

const char *RPN::OperatorException::what() const throw() {
	return _message.c_str();
}

RPN::OperatorException::OperatorException(const std::string &message) : _message(message) {}

RPN::OperatorException::~OperatorException() throw() {}