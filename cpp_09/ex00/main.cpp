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

	// colocar um iterator pra ver se ta vindo os dados
	return 0;
}
