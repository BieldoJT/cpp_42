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
	std::ifstream	archive;
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
	archive.close();
	return (0);
}

bool isValidNumber(const std::string& s)
{
	std::stringstream ss(s);
	double num;
	ss >> num;

	return (!ss.fail() && ss.eof());
}

int BitcoinExchange::loadInputData(const char* fileName)
{
	std::ifstream	infile;
	std::string		line;
	size_t			pos;
	char*			endPtr = NULL;

	infile.open(fileName);
	if(!(infile.is_open()))
		return (-1);
	if(!(std::getline(infile, line)))
		return (-2);
	if(line.compare("date | value") != 0)
		return (std::cout << "Data loading failed, bad format! " << "Header must be: \"date | value\"" << std::endl, -3);
	while(std::getline(infile, line))
	{std::pair<std::string, double> pair("", 0);
		pos = line.find(' ');
		if(pos == std::string::npos || line.substr(pos).length() < 4)
		{
			pair.first = "M" + line;
			pair.second = -1;
		}
		else
		{
			std::string valuePart = line.substr(pos + 3);
			if((line.substr(pos, 3).compare(" | ") != 0) || !(isValidNumber(valuePart)))
			{
				pair.first = "B" + line;
				pair.second = -1;
			}
			else
			{
				pair.first = line.substr(0, pos);
				pair.second = std::strtod(valuePart.c_str(), &endPtr);
			}
		}
		this->input.push_back(pair);
	}
	infile.close();
	return(0);
}


std::map<std::string, double> BitcoinExchange::getDatabase()
{
	return this->database;
}

std::list<std::pair<std::string, int>> BitcoinExchange::getInput()
{
	return this->input;
}
