#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <map>
#include <list>
#include <algorithm>

class BitcoinExchange
{
private:
	std::map<std::string, double> database;
	std::list<std::pair<std::string, int>> input;

public:
	BitcoinExchange(void);
	BitcoinExchange(BitcoinExchange const &copy);
	BitcoinExchange &operator=(BitcoinExchange const &copy);
	~BitcoinExchange();

	//member functions
	int	loadDatabase();
	int	loadInputData(const char* fileName);

	std::pair<std::string, double>	findPair(std::pair<std::string, double> sourcePair);
	std::pair<std::string, double>	inputControl(std::pair<std::string, double> pair);
	void	applyExchangeRate();

	std::map<std::string, double> getDatabase();
	std::list<std::pair<std::string, int>> getInput();

//	void printDatabase();
};

bool isValidNumber(const std::string& s);

#endif
