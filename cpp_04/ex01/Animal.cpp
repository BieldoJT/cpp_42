#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal Created" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destroyed" << std::endl;
}

Animal::Animal(Animal const &copy)
{
	*this = copy;
}

void Animal::setType(std::string &type)
{
	this->_type = type;
}

std::string Animal::getType(void) const
{
	return this->_type;
}

Animal &Animal::operator=(Animal const &copy)
{
	if(this != &copy)
	{
		this->_type = copy.getType();
	}
	return *this;
}

void Animal::makeSound(void) const
{
	std::cout << "Generic Animal Sound" << std::endl;
}
