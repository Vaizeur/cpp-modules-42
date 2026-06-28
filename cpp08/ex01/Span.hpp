#ifndef SPAN_HPP
# define SPAN_HPP
# include <vector>
# include <iostream>

class Span
{
	private:
		Span();
		std::vector<int> _numbers;
		unsigned	int _maxSize;
		bool			_isSorted;
	public :
		Span(unsigned int size);
		Span(const Span &other);
		Span& operator=(const Span &other);
		~Span();
		void	sort();
		void	checkSpan() const;
		void	addNumber(int number);
		void	addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int		shortestSpan();
		int		longestSpan();

		class SpanFullException : public std::exception {
			const char* what() const throw();
		};
		class SpanEmptyException : public std::exception {
			const char* what() const throw();
		};
		class SpanOneElementException : public std::exception {
			const char* what() const throw();
		};
};


#endif
