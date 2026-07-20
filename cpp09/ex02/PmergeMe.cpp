#include "PmergeMe.hpp"

PmergeMe::PmergeMe(const int argc,char **argv) : _startTime(0), _endTime(0)
{
	int value;
	for (int i = 1; i < argc; i++)
	{
		std::istringstream ss(argv[i]);
		if (!(ss >> value && ss.eof()))
			throw PmergeMeException("Error : invalid value " + std::string(argv[i]));
		if (value < 0)
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

template< typename T, typename U>
void	PmergeMe::createPairs(T &container, U &pairs){
	for (size_t i = 0 ; i < container.size() - 1; i += 2){
		const int left = container[i];
		const int right = container[i + 1];
		left > right ?
			pairs.push_back(std::make_pair(right, left)):
			pairs.push_back(std::make_pair(left, right))
		;
	}
}

template< typename T>
void	PmergeMe::extractWinners(typename PairStorage<T>::type &pairs, T &winners) {
	for (size_t i = 0; i < pairs.size(); ++i)
		winners.push_back(pairs[i].second);
}

template< typename T>
void	PmergeMe::rebuildPairs(T &sortedWinners, typename PairStorage<T>::type &pairs, typename PairStorage<T>::type &sortedPairs) {
	typename PairStorage<T>::type remaining = pairs;

	for (typename T::iterator it = sortedWinners.begin(); it != sortedWinners.end(); ++it) {
		for (typename PairStorage<T>::type::iterator pit = remaining.begin(); pit != remaining.end(); ++pit) {
			if (pit->second == *it) {
				sortedPairs.push_back(*pit);
				remaining.erase(pit);
				break;
			}
		}
	}
}

template <typename T , typename U>
T		PmergeMe::generateJacobsthal(int size, U &pairs) {
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
	int lastProcessed = -1;

	for (size_t i = 0; i < jacob.size(); i++) {
		int targetJacob = jacob[i] - 1;
		if (targetJacob >= size)
			targetJacob = size - 1;
		for (int j = targetJacob; j > lastProcessed; --j)
			order.push_back(j);
		lastProcessed = targetJacob;
		if (lastProcessed >= size - 1)
			break;
	}
	for (int i = lastProcessed + 1; i < size; i++)
		order.push_back(i);
	return order;
}

template< typename T>
void	PmergeMe::prepareContainer(T &sortedContainer, T& waitingContainer, typename PairStorage<T>::type &pairs){
	sortedContainer.push_back(pairs[0].first);
	sortedContainer.push_back(pairs[0].second);

	for (size_t i = 1; i < pairs.size(); ++i){
		sortedContainer.push_back(pairs[i].second);
		waitingContainer.push_back(pairs[i].first);
	}
}

template< typename T>
void    PmergeMe::insertBinary(T &jacobsthal, T &sortedContainer, typename PairStorage<T>::type &pairs, bool oddContainer, int oddValue) {
	for (typename T::iterator it = jacobsthal.begin(); it != jacobsthal.end(); ++it) {
		const int idx = *it;
		int value = pairs[idx + 1].first;
		int valuePairs = pairs[idx + 1].second;
		typename T::iterator itEnd = std::find(sortedContainer.begin(), sortedContainer.end(), valuePairs);
		typename T::iterator itToInsert = std::lower_bound(sortedContainer.begin(), itEnd, value);
		sortedContainer.insert(itToInsert, value);
	}
	if (oddContainer) {
		typename T::iterator it = std::lower_bound(sortedContainer.begin(), sortedContainer.end(), oddValue);
		sortedContainer.insert(it, oddValue);
	}
}

template< typename T>
void	PmergeMe::sortContainer(T &container) {
	if (container.size() <= 1)
		return;
	T currentContainer = container;
	const bool oddContainer = currentContainer.size() % 2 != 0;
	int oddValue = 0;
	if (oddContainer) {
		oddValue = currentContainer.back();
		currentContainer.pop_back();
	}

	typename PairStorage<T>::type pairs;
	createPairs(currentContainer, pairs);

	T winners;
	extractWinners<T>(pairs, winners);

	sortContainer(winners);
	typename PairStorage<T>::type sortedPairs;
	rebuildPairs(winners, pairs, sortedPairs);

	T sortedContainer;
	T waitingContainer;
	prepareContainer(sortedContainer, waitingContainer, sortedPairs);

	T jacobsthal = generateJacobsthal<T>(waitingContainer.size(), sortedPairs);
	insertBinary(jacobsthal, sortedContainer, sortedPairs, oddContainer, oddValue);
	container = sortedContainer;
}


const std::vector<int>& PmergeMe::getVector() const {
	return _vec;
}

void PmergeMe::startTime(){
	_startTime = clock();
}

void PmergeMe::endTime(){
	_endTime = clock();
}

double PmergeMe::getTime() const {
	return (_endTime - _startTime) * 1000.0 / CLOCKS_PER_SEC;
}

void PmergeMe::sort() {
	std::cout << "Before : " << *this << std::endl;
	startTime();
	sortContainer(_vec);
	endTime();
	const double durationVec = getTime();
	startTime();
	sortContainer(_deq);
	endTime();
	const double durationDeq = getTime();
	std::cout << "After  : " << *this << std::endl;
	std::cout << "Time to process a range of " << _vec.size() << " elements with std::vector : "<< durationVec << "ms" << std::endl;
	std::cout << "Time to process a range of " << _deq.size() << " elements with std::deque  : "<< durationDeq << "ms" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const PmergeMe& c) {
	const std::vector<int>& vec = c.getVector();
	for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it)
		out << *it << ' ';
	return out;
}

const char *PmergeMe::PmergeMeException::what() const throw (){
	return _message.c_str();
}

PmergeMe::PmergeMeException::PmergeMeException(const std::string &message) : _message(message) {}

PmergeMe::PmergeMeException::~PmergeMeException() throw() {}