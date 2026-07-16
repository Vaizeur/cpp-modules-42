#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <exception>
# include <string>
# include <vector>
# include <deque>
# include <iostream>
# include <sstream>

class PmergeMe
{
	private:
		std::vector<int>	_vec;
		std::deque<int>		_deq;
		PmergeMe();
		template< typename T>
		int		sortContainer(T &container);
	public:
		PmergeMe(int argc, char **argv);
		PmergeMe(const PmergeMe &other);
		PmergeMe& operator=(const PmergeMe &other);
		~PmergeMe();

		void	sort();

		class PmergeMeException : public std::exception
		{
			private :
				std::string _message;
			public :
				PmergeMeException(const std::string &message);
				virtual ~PmergeMeException() throw();
				virtual const char* what() const throw();
		};
};

#endif