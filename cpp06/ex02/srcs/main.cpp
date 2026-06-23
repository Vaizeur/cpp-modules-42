#include <cstdlib>
#include <ctime>
#include <iostream>
#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"


static Base *generate(void)
{
	const int value = std::rand() % 3;
	if (value == 0)
		return (new A());
	if (value == 1)
		return (new B());
	return (new C());
}

static void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "Class is a A type" << std::endl;
	if (dynamic_cast<B *>(p))
		std::cout << "Class is a B type" << std::endl;
	if (dynamic_cast<C *>(p))
		std::cout << "Class is a C type" << std::endl;
}

static void identify(Base &p)
{
	bool checked = false;
	try {
		dynamic_cast<A &>(p);
		std::cout << "Class is a A type" << std::endl;
		checked = true;
	}
	catch (std::exception &e) {}
	if (checked)
		return;
	try {
		dynamic_cast<B &>(p);
		std::cout << "Class is a B type" << std::endl;
		checked = true;
	}
	catch (std::exception &e) {}
	if (checked)
		return;
	try {
		dynamic_cast<C &>(p);
		std::cout << "Class is a C type" << std::endl;
		checked = true;
	}
	catch (std::exception &e) {}
}

int main(void)
{
	std::srand(std::time(NULL));
	for (int i = 0; i < 3; i++)
	{
		std::cout << "------------" << std::endl;
		Base* p = generate();
		identify(p);
		identify(*p);
		delete p;
	}

	return 0;
}
