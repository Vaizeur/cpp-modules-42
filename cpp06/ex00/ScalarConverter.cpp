#include "ScalarConverter.hpp"


std::string	parse(const std::string &value)
{
	std::string	res;
	// float -> int.int fini forcement par un f
	// double -> int.int
	// int -> seulement numeric
	// char -> seulement 1 char non numeric

	std::cout << "je suis la" << std::endl;
	if (value.length() == 1 && !std::isdigit(value[0]))
	{
		std::cout << "je suis la ici" << std::endl;
		int casted = value[0];
		std::cout << casted << std::endl;
		res += casted;
		std::cout << res << std::endl;
		return res;
	}
	return value;
	
}

void ScalarConverter::convert(const std::string &value) {

	std::string check = parse(value);


	double	newValue = std::strtod(check.c_str(), NULL);


	std::cout << newValue << std::endl;
	std::cout << "float: " << newValue << "f" << std::endl;
	std::cout << newValue << std::endl;
	std::cout << "int: " << static_cast<int>(newValue) << std::endl;
	
}
