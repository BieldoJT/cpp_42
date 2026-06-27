#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){
	std::cout << "Objeto criado" << std::endl;
}

BitcoinExchange::~BitcoinExchange(){
	std::cout << "Objecto destruido" << std::endl;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &copy)
{
	std::cout << "Copiando rasamente" << std::endl;
	*this = copy;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &copy){
	if(this != &copy)
	{
		this->database = copy.database;
		this->input = copy.input;
	}

	return *this;
}

int BitcoinExchange::loadDatabase(){
	std::fstream	archive;
	std::string		line;
	size_t			pos;
	char*			endPtr = NULL;

	archive.open("data.csv");
	if(!(archive.is_open()))
		return (-1);
	if(!(std::getline(archive, line)))
		return (-2);
	while (std::getline(archive, line))
	{
		std::pair<std:: string, double> pair("", 0);
		pos = line.find(',');
		if(pos == std::string::npos)
			return (-3);
		pair.first = line.substr(0, pos);
		pair.second = std::strtod((line.substr(pos + 1)).c_str(), &endPtr);
		this->database.insert(pair);
	}


}
