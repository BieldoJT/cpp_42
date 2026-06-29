#include <iostream>
#include "BitcoinExchange.hpp"

int main(int argc, char** argv)
{
	if(argc != 2)
		return (std::cout << "Error: Please, enter a file as an argument!\n", 1);

	BitcoinExchange btc;
	int ret1;
	int ret2;

	ret1 = btc.loadDatabase();
	// std::cout << "return: " << ret1 << std::endl;
	// std::cout << "---------------------------------" << std::endl;
	ret2 = btc.loadInputData(argv[1]);
	// std::cout << "return: " << ret2 << std::endl;
	// std::cout << "---------------------------------" << std::endl;

	if((ret1 == 0) && (ret2 == 0))
		btc.applyExchangeRate();

	return 0;
}
