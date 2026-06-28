
#include "Span.hpp"
#include <algorithm>

Span::Span() : _maxSize(0) , _isSorted(false) {}

Span::Span(unsigned int size) : _maxSize(size) , _isSorted(false) {}

Span& Span::operator=(const Span& other) {
	if (this != &other){
		_numbers = other._numbers;
		_maxSize = other._maxSize;
		_isSorted = other._isSorted;
	}
	return *this;
}

Span::~Span() {}

void Span::sort()
{
	if (_isSorted)
		return;
	std::sort(_numbers.begin(), _numbers.end());
	_isSorted = true;
}
void Span::checkSpan() const
{
	if (_numbers.empty())
		throw SpanEmptyException();
	if (_numbers.size() == 1)
		throw SpanOneElementException();
}

void Span::addNumber(const int number){
	if (_maxSize <= _numbers.size())
		throw SpanFullException();
	if (_isSorted && number < _numbers.back())
		_isSorted = false;
	_numbers.push_back(number);
}
void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (std::distance(begin, end) + _numbers.size() > _maxSize)
		throw SpanFullException();
	_numbers.insert(_numbers.end(), begin, end);
	_isSorted = false;
}

int Span::longestSpan()
{
	checkSpan();
	sort();
	return _numbers.back() - *_numbers.begin();
}

int Span::shortestSpan()
{
	checkSpan();
	sort();
	const std::vector<int>::iterator begin = _numbers.begin();
	const std::vector<int>::iterator end = _numbers.end();
	int	min = *(begin + 1) - *begin;
	for (std::vector<int>::iterator it = begin + 1; it != end; ++it) {
		if (*it - *(it-1) < min)
			min = *it - *(it-1);
	}
	return min;
}

const char* Span::SpanFullException::what() const throw() {
	return "Full Span";
}

const char* Span::SpanEmptyException::what() const throw() {
	return "Empty Span";
}

const char* Span::SpanOneElementException::what() const throw() {
	return "Span contain only one Element";
}
