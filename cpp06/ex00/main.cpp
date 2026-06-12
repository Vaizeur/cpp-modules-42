#include "ScalarConverter.hpp"

int main(int argc, char const *argv[])
{
	if (argc != 2) {
		std::cerr << "./ex00 <value>" << std::endl;
		return 0;
	}
	std::string value = argv[1];
	ScalarConverter::convert(value);
	return 0;
}
