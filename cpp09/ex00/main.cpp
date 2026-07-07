#include <iostream>
#include "BitcoinExchange.hpp"

int main(int argc, char** argv) {
	if (argc < 2) {
		std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
		return (1);
	}
	BitcoinExchange bitcoinExchange(argv[1]);
	try {
		bitcoinExchange.init();
		bitcoinExchange.process();
	}catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}