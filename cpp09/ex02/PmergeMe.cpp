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
void	PmergeMe::sortPairs(T &pairs) {
	if (pairs.size() <= 1)
		return;
	for (int i = 1; i < static_cast<int>(pairs.size()); i++) {
		typename T::value_type currentPairs = pairs[i];
		int j = i - 1;
		while (j >= 0 && pairs[j].second > currentPairs.second) {
			pairs[j + 1] = pairs[j];
			j--;
		}
		pairs[j + 1] = currentPairs;
	}
}

template <typename T , typename U>

T	PmergeMe::generateJacobsthal(int size, U &pairs)
{
	(void) pairs;

	typename ContainerConvert<U>::type jacob;
	typename ContainerConvert<U>::type order;

	jacob.push_back(1);
	jacob.push_back(3);
	int nextValue = jacob[jacob.size()-1] + 2 * jacob[jacob.size()-2];
	while (jacob.back() < size) {
		jacob.push_back(nextValue);
		nextValue = jacob[jacob.size()-1] + 2 * jacob[jacob.size()-2];
	}
	int lastProcessed = 0;

	for (size_t i = 0; i < jacob.size(); i++) {
		int targetJacob = jacob[i] - 1;
		if (targetJacob >= size)
			targetJacob = size - 1;
		for (int j = targetJacob; j > lastProcessed; --j) {
			order.push_back(j);
		}
		lastProcessed = targetJacob;
		if (lastProcessed >= size - 1)
			break;
	}
	for (int i = lastProcessed + 1; i < size; i++)
		order.push_back(i);
	return order;
}

template< typename T>
void	PmergeMe::sortContainer(T &container) {
	if (container.size() <= 1)
		return;

	bool dispatcherHandler = false;
	const bool oddContainer = container.size() % 2 != 0;

	int oddValue = 0;
	if (oddContainer)
		oddValue = container.back();
	(void) oddValue;
	typename PairStorage<T>::type pairs;
	for (size_t i = 0 ; i < container.size() - 1; i += 2){
		const int left = container.at(i);
		const int right = container.at(i + 1);

		dispatcherHandler = left > right;
		dispatcherHandler ?
			pairs.push_back(std::make_pair(right, left)):
			pairs.push_back(std::make_pair(left, right))
		;
	}

	sortPairs(pairs);
	T sortedContainer;
	T waitingContainer;

	sortedContainer.push_back(pairs[0].first);
	sortedContainer.push_back(pairs[0].second);

	for (size_t i = 1; i < pairs.size(); ++i){
		sortedContainer.push_back(pairs[i].second);
		waitingContainer.push_back(pairs[i].first);
	}

	T jacobsthal = generateJacobsthal<T >(waitingContainer.size(), pairs);

	/*
	std::cout << "LA SUITE " << std::endl;
	for (typename T::iterator it = jacobsthal.begin(); it != jacobsthal.end(); ++it)
		std::cout << *it << std::endl;
	std::cout << "FIN DE LA SUITE " << std::endl;
	*/

	//TODO: faire la suite de Jacobsthal

	container = sortedContainer;
}

void PmergeMe::sort() {
	std::cout << "Before : ";
	for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	sortContainer(_vec);
	const int durationVec = 0;
	//const int durationDeq = sortContainer(_deq);
	std::cout << "After : ";
	for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "Time to process a range of " << _vec.size() << "elements with std::vector : "<< durationVec << "us" << std::endl;
	//std::cout << "Time to process a range of " << _deq.size() << "elements with std::deque : "<< durationDeq << "us" << std::endl;
}

const char *PmergeMe::PmergeMeException::what() const throw (){
	return _message.c_str();
}

PmergeMe::PmergeMeException::PmergeMeException(const std::string &message) : _message(message) {}

PmergeMe::PmergeMeException::~PmergeMeException() throw() {}

