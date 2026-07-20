#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <exception>
# include <string>
# include <vector>
# include <deque>
# include <sstream>
# include <iostream>

template<typename T>
struct PairStorage;

template<>
struct PairStorage<std::vector<int> > {
	typedef std::vector<std::pair<int,int> > type;
};

template<>
struct PairStorage<std::deque<int> > {
	typedef std::deque<std::pair<int,int> > type;
};

template<typename T>
struct ContainerConvert;

template<>
struct ContainerConvert<std::vector<std::pair<int,int > > > {
	typedef std::vector<int> type;
};

template<>
struct ContainerConvert<std::deque<std::pair<int,int > > > {
	typedef std::deque<int> type;
};

class PmergeMe
{
	private:
		std::vector<int>	_vec;
		std::deque<int>		_deq;
		PmergeMe();

		template< typename T>
		void		sortContainer(T &container);

		template< typename T>
		void		sortPairs(T &pairs);

		template< typename T, typename U>
		T			generateJacobsthal(int size, U &pairs);

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