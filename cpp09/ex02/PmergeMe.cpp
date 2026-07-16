#include "PmergeMe.hpp"


PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(const int argc,char **argv) {
	int value;
	for (int i = 1 ; i < argc; i++) {
		std::istringstream ss(argv[i]);
		if (!(ss >> value && ss.eof()))
			throw PmergeMeException("Error : invalid value " + std::string(argv[i]));
		if (value <= 0)
			throw PmergeMeException("Error : value must be non-negative");
		_vec.push_back(value);
		_deq.push_back(value);
	}
}

PmergeMe::PmergeMe(const PmergeMe &other) {
	*this = other;
}

PmergeMe&	PmergeMe::operator=(const PmergeMe &other) {
	if (this != &other) {
		_vec = other._vec;
		_deq = other._deq;
	}
	return *this;
}

PmergeMe::~PmergeMe(){}

template< typename T>
int		PmergeMe::sortContainer(T &container) {
	T win;
	T looser;

	return (0);
}

void PmergeMe::sort() {
	std::cout << "Before : ";
	for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	const int durationVec = sortContainer(_vec);
	const int durationDeq = sortContainer(_deq);
	std::cout << "After : ";
	for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "Time to process a range of " << _vec.size() << "elements with std::vector : "<< durationVec << "us" << std::endl;
	std::cout << "Time to process a range of " << _deq.size() << "elements with std::deque : "<< durationDeq << "us" << std::endl;
}

const char *PmergeMe::PmergeMeException::what() const throw (){
	return _message.c_str();
}

PmergeMe::PmergeMeException::PmergeMeException(const std::string &message) : _message(message) {}

PmergeMe::PmergeMeException::~PmergeMeException() throw() {}

