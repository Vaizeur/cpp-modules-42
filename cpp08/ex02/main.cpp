#include <iostream>
#include <list>
#include "MutantStack.hpp"

static void printTitle(const std::string& title)
{
	std::cout << "\n========== " << title << " ==========\n";
}

void subjectTest()
{
	printTitle("SUBJECT TEST");

	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << "Top : " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Size : " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	std::cout << "Forward iteration :" << std::endl;
	for (MutantStack<int>::iterator it = mstack.begin();it != mstack.end(); ++it)
		std::cout << *it << std::endl;
	std::stack<int> s(mstack);
}

void copyConstructorTest()
{
	printTitle("COPY CONSTRUCTOR");
	MutantStack<int> original;
	for (int i = 0; i < 5; i++)
		original.push(i * 10);
	MutantStack<int> copy(original);
	std::cout << "Original :" << std::endl;
	for (MutantStack<int>::iterator it = original.begin(); it != original.end(); ++it)
		std::cout << *it << " ";
	std::cout << "\nCopy :" << std::endl;
	for (MutantStack<int>::iterator it = copy.begin();
			it != copy.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void assignationTest()
{
	printTitle("ASSIGNATION");

	MutantStack<int> a;
	MutantStack<int> b;
	for (int i = 1; i <= 5; i++)
		a.push(i);
	b = a;
	std::cout << "Stack b :" << std::endl;
	for (MutantStack<int>::iterator it = b.begin(); it != b.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void reverseIteratorTest()
{
	printTitle("REVERSE ITERATOR");
	MutantStack<int> stack;
	for (int i = 1; i <= 5; i++)
		stack.push(i);
	for (MutantStack<int>::reverse_iterator it = stack.rbegin(); it != stack.rend(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void constIteratorTest()
{
	printTitle("CONST ITERATOR");
	MutantStack<int> tmp;
	for (int i = 0; i < 5; i++)
		tmp.push(i + 42);
	const MutantStack<int> stack(tmp);
	for (MutantStack<int>::const_iterator it = stack.begin(); it != stack.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void stackFunctionsTest()
{
	printTitle("STACK FUNCTIONS");
	MutantStack<int> stack;
	std::cout << "Empty : " << stack.empty() << std::endl;
	stack.push(10);
	stack.push(20);
	stack.push(30);
	std::cout << "Top : " << stack.top() << std::endl;
	std::cout << "Size : " << stack.size() << std::endl;
	stack.pop();
	std::cout << "Top after pop : " << stack.top() << std::endl;
	std::cout << "Size after pop : " << stack.size() << std::endl;
}

void listComparison()
{
	printTitle("COMPARISON WITH std::list");

	MutantStack<int> mutant;
	std::list<int> list;

	for (int i = 0; i < 10; i++) {
		mutant.push(i);
		list.push_back(i);
	}

	MutantStack<int>::iterator mit = mutant.begin();
	std::list<int>::iterator lit = list.begin();

	while (mit != mutant.end() && lit != list.end()){
		std::cout << *mit << " | " << *lit << std::endl;
		++mit;
		++lit;
	}
}

int main()
{
	subjectTest();
	copyConstructorTest();
	assignationTest();
	reverseIteratorTest();
	constIteratorTest();
	stackFunctionsTest();
	listComparison();

	return 0;
}