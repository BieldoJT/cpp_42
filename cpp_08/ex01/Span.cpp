#include "Span.hpp"

Span::Span(unsigned int N): _maxSize(N){};

Span::Span(const Span &copy): _maxSize(copy._maxSize){}

Span &Span::operator=(const Span &other){
	if(this != &other)
	{
		this->_maxSize = other._maxSize;
	}
	return *this;
}

Span::~Span(){};

const char* Span::LimitReached::what() const throw()
{
	return "The Limit has been reached";
}
const char* Span::NoNumbersInTheList::what() const throw()
{
	return "The Span hasn't numbers";
}
const char* Span::OneNumberOnTheList::what() const throw()
{
	return "It must have two or more numbers";
}

void Span::addNumber(unsigned int N)
{
	try{
		if(this->listElements.size() == this->_maxSize)
			throw LimitReached();
		this->listElements.push_back(N);

		//std::list<unsigned int> list = this->listElements;
		//std::list<unsigned int>::iterator it;
		//for(it = list.begin(); it != list.end(); ++it){
		//	std::list<unsigned int>::iterator num = it;
		//	std::cout << *it;
		//		if(++num != list.end())
		//			std::cout << ",";
		//}
		//std::cout << "\n";
	}
	catch(std::exception &e){
		std::cout << "\033[1;31m" << e.what() << "\033[0m" << std::endl;
	}
}

int Span::shortestSpan(){

	if(this->listElements.empty())
		throw NoNumbersInTheList();
	else if(this->listElements.size() == 1)
		throw OneNumberOnTheList();

	std::list<unsigned int> list = this->listElements;
	std::list<unsigned int>::iterator it;
	std::list<unsigned int>::iterator last;
	int result = 0;
	for(it = list.begin(); it != list.end(); ++it){
		if(it == list.begin()){
			last = it;
			continue;
		}
		int diff = *it - *last;
		int value = diff < 0?-diff:diff;
		if(!result)
			result = value;
		else if (result > value){
			result = value;
		}
		++last;
	}
	return result;
}

int Span::longestSpan(){

	if(this->listElements.empty())
		throw NoNumbersInTheList();
	else if(this->listElements.size() == 1)
		throw OneNumberOnTheList();

	std::list<unsigned int> list = this->listElements;
	std::list<unsigned int>::iterator it;
	std::list<unsigned int>::iterator last;

	int result = 0;
	for(it = list.begin(); it != list.end(); ++it){
		if(it == list.begin()){
			last = it;
			continue;
		}
		int diff = *it - *last;
		int value = diff < 0?-diff:diff;
		if(!result)
			result = value;
		else if (result < value){
			result = value;
		}
		++last;
	}
	return result;
}

void Span::addNumber(std::list<unsigned int>::iterator begin, std::list<unsigned int>::iterator end){

	try{
		if(this->listElements.size() + std::distance(begin, end) > this->_maxSize)
			throw LimitReached();
		this->listElements.insert(this->listElements.end(), begin, end);
	}
	catch(std::exception &e){
		std::cout << "\033[1;31m" << e.what() << "\033[0m" << std::endl;
	}
}
