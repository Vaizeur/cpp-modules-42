#include <iostream>
#include <list>
#include <stack>
#include "MutantStack.hpp"

void subjectTest() {
	std::cout << "SUBJECT TEST" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator iter = mstack.end();
	++it;
	--it;
	while (it != iter)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
}

void listTest() {
	std::cout << "LIST TEST" << std::endl;
	std::list<int> mstack;
	mstack.push_back(5);
	mstack.push_back(17);
	std::cout << mstack.back() << std::endl;
	mstack.pop_back();
	std::cout << mstack.size() << std::endl;
	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	//[...]
	mstack.push_back(0);
	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator iter = mstack.end();
	++it;
	--it;
	while (it != iter)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::list<int> s(mstack);
}

int main()
{
	subjectTest();
	listTest();
	return 0;
}
