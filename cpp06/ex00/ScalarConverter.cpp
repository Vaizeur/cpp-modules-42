#include "ScalarConverter.hpp"
#include "struct.h"


bool validFormat(const std::string& value)
{
	bool	comaCheck = false;
	bool	signCheck = false;
	bool	numberCheck = false;

	if (value.length() == 1 && !std::isdigit(value[0]))
		return true;	
	std::string::const_iterator it = value.begin();
	while (it != value.end())
	{
		if (*it == '-' || *it == '+')
		{
			if (signCheck || it != value.begin())
				return false;
			signCheck = true;
		}		
		else if (*it == '.')
		{
			if (comaCheck || !numberCheck || it + 1 == value.end())
				return false;
			comaCheck = true;
		}
		else if (*it == 'f')
		{
			if (!numberCheck || !comaCheck || *(it - 1) == '.')
				return false;
			++it;
			break;
		}
		else if (!std::isdigit(*it))
			return false;
		else
			numberCheck = true;
		++it;
	}
	return (numberCheck && it == value.end());
}

void ScalarConverter::convert(const std::string &value) {
	
	//TokenResult result;
	
	if (!validFormat(value)){
		std::cout << "Erreur de format" << std::endl;
		return ;
	}
	//result = parseValue();

	//printConvert(result);
}
