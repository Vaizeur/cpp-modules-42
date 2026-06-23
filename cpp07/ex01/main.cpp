#include <iostream>
#include "iter.hpp"

static void printInt(const int& value) {
	std::cout << "print Int:" << value << std::endl;
}

static void increment(int& value) {
	value++;
}

int main()
{
	int tab[] = {1, 2, 3, 4, 5};
	std::cout << "BEFORE INCREMENT" << std::endl;
	iter(tab, 5, printInt);
	iter(tab, 5, increment);
	std::cout << "AFTER INCREMENT" << std::endl;
	iter(tab, 5, printInt);
}