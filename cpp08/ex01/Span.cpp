
#include "Span.hpp"

#include <algorithm>
#include <limits>

Span::Span() : _maxSize(0), _min(0), _max(0) {}

Span::Span(unsigned int size) : _maxSize(size), _min(0), _max(0) {}

Span& Span::operator=(const Span& other) {
	if (this != &other){
		_numbers = other._numbers;
		_maxSize = other._maxSize;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int number){
	if (_maxSize >= _numbers.size() + 1)
		return ;
	_numbers.push_back(number);
}

int Span::longestSpan()
{
	int longestSpan = 0;

	std::sort(_numbers.begin(), _numbers.end());
	std::vector<int>::iterator it;
	for (it = _numbers.begin(); it != _numbers.end(); ++it)
	{

	}
	return longestSpan;
}


