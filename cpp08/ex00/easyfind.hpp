#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <algorithm>
# include <iostream>
# include <exception>

class EasyFindException : public std::exception
{
	public:
		const char* what() const throw() {
			return "Can't found value in container";
		}
};

template< typename T>

void easyfind(T &container, int value)
{
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw EasyFindException();
	std::cout << "Value (" << value << ") found in container" << std::endl;
}

#endif
