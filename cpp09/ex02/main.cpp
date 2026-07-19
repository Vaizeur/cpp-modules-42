
#include <iostream>
#include "PmergeMe.hpp"

int main(int argc, char  **argv)
{
	if (argc < 2){
		std::cerr << "usage : ./PmergeMe <integers>" << std::endl;
		return (1);
	}
	try {
		PmergeMe algo(argc, argv);
		algo.sort();
	}
	catch(const std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
