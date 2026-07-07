#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

#include <map>
#include <exception>
#include <string>

class BitcoinExchange {
	private:
		BitcoinExchange();
		std::string							_filename;
		std::string							_currentLine;
		std::map<std::string, float>		_exchangeMap;
	public:
		BitcoinExchange(const std::string &fileName);
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		void		init();
		void		parseLine();
		void		process();
		void		processLine();

		void		checkDate(const std::string &date) const;
		void		checkValue(const std::string &value, float limit) const;

		static	std::string	trimLine(const std::string &line);

		class BitcoinExchangeException : public std::exception {
			private :
				std::string _message;
			public :
				BitcoinExchangeException(const std::string &message);
				virtual ~BitcoinExchangeException() throw();
				virtual const char* what() const throw();
		};
};

#endif
