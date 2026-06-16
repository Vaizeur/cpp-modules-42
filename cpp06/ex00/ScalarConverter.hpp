#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

# include <iostream>
# include <cstdlib>
# include <string>
# include <iomanip>
# include <cmath>
# include <limits>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const &other);
		~ScalarConverter();
		ScalarConverter	&operator=(ScalarConverter const &other);
	public:
		void static convert(const std::string &value);
};

#endif