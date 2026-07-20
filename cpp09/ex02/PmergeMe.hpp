#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <exception>
# include <string>
# include <vector>
# include <deque>
# include <sstream>
# include <iostream>
# include <algorithm>
# include <sys/time.h>

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
		clock_t				_startTime;
		clock_t				_endTime;
		std::vector<int>	_vec;
		std::deque<int>		_deq;
		PmergeMe();

		void	startTime();
		void	endTime();
		double	getTime() const;

		template< typename T>
		void		sortContainer(T &container);

		template<typename T>
		static void extractWinners(typename PairStorage<T>::type &pairs, T &winners);

		template<typename T>
		void rebuildPairs(T &sortedWinners, typename PairStorage<T>::type &pairs, typename PairStorage<T>::type &sortedPairs);

		template< typename T, typename U>
		T			generateJacobsthal(int size, U &pairs);

		template< typename T>
		void	insertBinary(T &jacobsthal, T &sortedContainer,typename PairStorage<T>::type &pairs, bool oddContainer, int oddValue);

		template< typename T>
		static void	prepareContainer(T &sortedContainer, T& waitingContainer,  typename PairStorage<T>::type &pairs);

		template< typename T, typename U>
		static void createPairs(T &container, U &pairs);

	public:
		PmergeMe(int argc, char **argv);
		PmergeMe(const PmergeMe &other);
		PmergeMe& operator=(const PmergeMe &other);
		~PmergeMe();

		void	sort();
		const std::vector<int>& getVector() const;
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

std::ostream &operator<<(std::ostream &out, const PmergeMe &c);

#endif