#ifndef SPAN_HPP
# define SPAN_HPP
#include <vector>

class Span
{
	private:
		Span();
		std::vector<int> _numbers;
		unsigned	int _maxSize;
		int				_min;
		int				_max;
	public :
		Span(unsigned int size);
		Span(const Span &other);
		Span& operator=(const Span &other);
		~Span();
		void	addNumber(int number);
		int		shortestSpan();
		int		longestSpan();
};


#endif
