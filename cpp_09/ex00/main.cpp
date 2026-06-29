#include <iostream>
#include "BitcoinExchange.hpp"

int main(int argc, char** argv)
{
	if(argc != 2)
		return (std::cout << "Error: Please, enter a file as an argument!\n", 1);

	std::cout << argv[1] << std::endl;
	std::cout << "RODEI" << std::endl;

	BitcoinExchange big;

	big.loadDatabase();
	big.loadInputData(argv[1]);

//	std::map<std::string, double> db = big.getDatabase();
//	for (std::map<std::string, double>::iterator it = db.begin(); it != db.end(); ++it)
//		std::cout << it->first << " => " << it->second << std::endl;

	std::list<std::pair<std::string, int>> input = big.getInput();
	for (std::list<std::pair<std::string, int>>::iterator it = input.begin(); it != input.end(); it++){
		std::cout << it->first << " => " << it->second << std::endl;
	}
	std::cout << std::endl;
	return 0;
}
