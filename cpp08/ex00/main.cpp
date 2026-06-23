#include "easyfind.hpp"
#include <deque>
#include <list>
#include <vector>

int main(void)
{
	std::cout << "Test Vector" << std::endl;
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	try {
		easyfind(vec,1);
		easyfind(vec,2);
		easyfind(vec,3);
		easyfind(vec,4);
	}catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}
	std::cout << "Test List" << std::endl;
	std::list<int> list;
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	try {
		easyfind(list, 1);
		easyfind(list, 2);
		easyfind(list, 3);
		easyfind(list, 4);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "Test Deque" << std::endl;
	std::deque<int> deque;
	deque.push_back(1);
	deque.push_back(2);
	deque.push_back(3);
	try {
		easyfind(deque, 1);
		easyfind(deque, 2);
		easyfind(deque, 3);
		easyfind(deque, 4);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
