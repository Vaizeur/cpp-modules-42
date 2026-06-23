#include <iostream>
#include "Array.hpp"

int main()
{
	std::cout << "=== TEST ARRAY INT ===" << std::endl;

	Array<int> a(5);

	for (unsigned int i = 0; i < a.size(); i++)
		a[i] = i * 10;

	for (unsigned int i = 0; i < a.size(); i++)
		std::cout << "a[" << i << "] = " << a[i] << std::endl;

	std::cout << "\n=== TEST COPY CONSTRUCTOR ===" << std::endl;

	Array<int> b(a);

	for (unsigned int i = 0; i < b.size(); i++)
		std::cout << "b[" << i << "] = " << b[i] << std::endl;

	std::cout << "\n=== TEST ASSIGNATION ===" << std::endl;

	Array<int> c;
	c = a;

	for (unsigned int i = 0; i < c.size(); i++)
		std::cout << "c[" << i << "] = " << c[i] << std::endl;

	std::cout << "\n=== TEST INDEPENDANCE ===" << std::endl;

	a[0] = 999;

	std::cout << "a[0] = " << a[0] << std::endl;
	std::cout << "b[0] = " << b[0] << std::endl;
	std::cout << "c[0] = " << c[0] << std::endl;

	std::cout << "\n=== TEST OUT RANGE ===" << std::endl;
	try
	{
		std::cout << "test : " << a[900] << std::endl;
	}catch (std::exception& e)
	{
		std::cout << "\nException: " << e.what() << std::endl;
	}
	return 0;
}