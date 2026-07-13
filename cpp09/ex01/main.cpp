
#include <iostream>
#include "RPN.hpp"

int main(int argc, char const *argv[])
{
	if (argc < 2){
		std::cerr << "usage : ./RPN <expression>" << std::endl;
		return (1);
	}
	RPN expr(argv[1]);
	expr.calcul();
	return (0);
}
