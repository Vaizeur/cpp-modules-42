#include "BitcoinExchange.hpp"

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _currentLine(other._currentLine), _exchangeMap(other._exchangeMap) {}

BitcoinExchange::BitcoinExchange(const std::string &fileName) : _filename(fileName) {

}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &other) {
	if (this != &other) {
		_filename = other._filename;
		_exchangeMap = other._exchangeMap;
		_currentLine = other._currentLine;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange(){}

void BitcoinExchange::init() {
	std::ifstream ifs("data.csv", std::ios::in);
	if (!ifs.is_open())
		throw BitcoinExchangeException("Error: could not open `data.csv` file");
	while (std::getline(ifs, _currentLine))
		parseLine();
}

void BitcoinExchange::parseLine() {
	size_t pos = _currentLine.find(',');
	if (pos == std::string::npos)
		throw BitcoinExchangeException("Error: in data.csv file => " + _currentLine);
	const std::string date = _currentLine.substr(0, pos);
	try {
		checkDate(date);
	} catch (std::exception &e) {
		throw BitcoinExchangeException("Error: date format in data.csv file => " + _currentLine);
	}
	const std::string value = _currentLine.substr(pos + 1);
	try {
		checkValue(value);
	} catch (std::exception &e) {
		throw BitcoinExchangeException("Error: value in data.csv file => " + _currentLine);
	}
	_exchangeMap.insert(std::make_pair(date, std::strtof(value.c_str(), NULL)));
}

void BitcoinExchange::process() {
	std::ifstream ifs(_filename.c_str(), std::ios::in);
	if (!ifs.is_open())
		throw BitcoinExchangeException("could not open file");
	while (std::getline(ifs, _currentLine)) {
		try {
			processLine();
		} catch(BitcoinExchangeException &e) {
			std::cout << e.what() << std::endl;
		}
	}
}

void BitcoinExchange::processLine() {
	std::string date;
	std::string value;

	size_t pos = _currentLine.find('|');
	if (pos == std::string::npos)
		throw BitcoinExchangeException("Error: bad input => " + _currentLine);
	date = _currentLine.substr(0, pos);
	value = _currentLine.substr(pos + 1);

	checkDate(date);
	checkValue(value);
}

void BitcoinExchange::checkDate(const std::string &date) const {
	int		year,month,day;
	char	sep1, sep2;
	std::string trimmedDate = trimLine(date);
	std::istringstream iss(trimmedDate);
	if (!(iss >> year >> sep1 >> month >> sep2 >> day&& sep1 == '-' && sep2 == '-' && iss.eof()))
		throw BitcoinExchangeException("Error: bad input => " + date);
	static std::map<int, int> calendarMap;
	if (calendarMap.empty()) {
		calendarMap.insert(std::pair<int, int> (1,31));
		calendarMap.insert(std::pair<int, int> (2,28));
		calendarMap.insert(std::pair<int, int> (3,31));
		calendarMap.insert(std::pair<int, int> (4,30));
		calendarMap.insert(std::pair<int, int> (5,31));
		calendarMap.insert(std::pair<int, int> (6,30));
		calendarMap.insert(std::pair<int, int> (7,31));
		calendarMap.insert(std::pair<int, int> (8,31));
		calendarMap.insert(std::pair<int, int> (9,30));
		calendarMap.insert(std::pair<int, int> (10,31));
		calendarMap.insert(std::pair<int, int> (11,30));
		calendarMap.insert(std::pair<int, int> (12,31));
	}
	if (month < 1 || month > 12 || day < 1 || day > 31)
		throw BitcoinExchangeException("Error: bad input => " + _currentLine);
	if (day > calendarMap.find(month)->second)
		throw BitcoinExchangeException("Error: bad input => " + _currentLine);
}

void BitcoinExchange::checkValue(const std::string &value, const float limit) const {

	float floatValue;

	if (std::istringstream(value) >> floatValue)
		throw BitcoinExchangeException("Error: bad input => " + _currentLine);
	std::cout << floatValue << std::endl;
	if (floatValue <= limit)
		throw BitcoinExchangeException("Error: bad input => " + _currentLine);
}

std::string BitcoinExchange::trimLine(const std::string &line)
{
	const char *whitespace = " \t\n\r\f\v";

	const size_t start = line.find_first_not_of(whitespace);
	if (start == std::string::npos)
		return "";
	const size_t end = line.find_last_not_of(whitespace);
	return line.substr(start, end - start + 1);
}

const char *BitcoinExchange::BitcoinExchangeException::what() const throw() {
	return _message.c_str();
}

BitcoinExchange::BitcoinExchangeException::BitcoinExchangeException(const std::string &message) : _message(message) {}

BitcoinExchange::BitcoinExchangeException::~BitcoinExchangeException() throw() {}
