#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}
ScalarConverter::~ScalarConverter(){}
ScalarConverter::ScalarConverter(ScalarConverter const &other) {
	(void) other;
}
ScalarConverter &ScalarConverter::operator=(ScalarConverter const &other) {
	(void) other;
	return *this;
}

bool	isPseudoLiteral(const std::string& value) {
	const std::string lists[6] = {
		"-inf", "+inf", "nan",
		"-inff", "+inff", "nanf"
	};
	for (int i = 0; i < 6; i++) {
		if (value == lists[i])
			return true;
	}
	return false;
}

bool	validFormat(const std::string& value)
{
	bool	comaCheck = false;
	bool	signCheck = false;
	bool	numberCheck = false;

	if (isPseudoLiteral(value))
		return true;
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

void	printValue(
	char	c, bool cError,
	int		i, bool iError,
	float	f, bool fError,
	double	d, bool dError)
{
	if (cError)
		std::cout << "char: impossible" << std::endl;
	else if (c < 32 || c > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;

	if (iError)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;
	std::cout << std::fixed << std::setprecision(1);

	if (fError)
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << f << "f" << std::endl;

	if (dError)
		std::cout << "double: impossible" << std::endl;
	else
		std::cout << "double: " << d << std::endl;
}


void	handleChar(char c)
{
	printValue(c,false,static_cast<int>(c),false,static_cast<float>(c),false, static_cast<double>(c),false);
}

void	handleNumber(const std::string& value)
{
	double d = std::strtod(value.c_str(), NULL);

	bool cError = std::isnan(d) || std::isinf(d) || d < std::numeric_limits<char>::min() || d > std::numeric_limits<char>::max();
	bool iError = std::isnan(d) || std::isinf(d) || d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max();
	bool fError = std::isinf(d) || d < -std::numeric_limits<float>::max() || d > std::numeric_limits<float>::max();
	bool dError = std::isinf(d) || d < -std::numeric_limits<double>::max() || d > std::numeric_limits<double>::max();

	printValue(
		static_cast<char>(d), cError,
		static_cast<int>(d), iError,
		static_cast<float>(d), fError,
		d, dError
	);
}

void	handleFloat(const std::string& value)
{
	const std::string newValue = value.substr(0, value.length() - 1);
	handleNumber(newValue);
}

void	handlePseudoLiteral(const std::string& value)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (value == "-inf" || value == "+inf" || value == "nan")
	{
		std::cout << "float: " << value << "f" << std::endl;
		std::cout << "double: " << value << std::endl;
		return;
	}
	std::cout << "float: " << value << std::endl;
	std::cout << "double: " << value.substr(0, value.length() - 1) << std::endl;
}

void ScalarConverter::convert(const std::string &value) {
	if (!validFormat(value)){
		printValue('0', true, 0, true, 0, true, 0, true);
		return ;
	}
	if (isPseudoLiteral(value))
		handlePseudoLiteral(value);
	else if (value.length() == 1 && !std::isdigit(value[0]))
		handleChar(value[0]);
	else if (value[value.length() - 1] == 'f')
		handleFloat(value);
	else
		handleNumber(value);
}
