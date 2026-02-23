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

void Span::addNumber(unsigned int N)
{
	try{
		if(this->listElements.size() == this->_maxSize)
			throw LimitReached();
		this->listElements.push_back(N);

		std::list<unsigned int> list = this->listElements;
		std::list<unsigned int>::iterator it;

		for(it = list.begin(); it != list.end(); ++it){
			std::cout << *it;
		}
		std::cout << "\n";
	}
	catch(std::exception &e){
		std::cout << "\033[1;31m" << e.what() << "\033[0m" << std::endl;
	}
}
