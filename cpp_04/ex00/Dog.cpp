#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog created" << std::endl;
	this->_type = "dog";
}

Dog::~Dog()
{
	std::cout << "Dog destroyed" << std::endl;
}

Dog::Dog(Dog const &copy) : Animal(copy)
{
	*this = copy;
}

Dog &Dog::operator=(Dog const &copy)
{
	if (this != &copy)
	{
		this->_type = copy.getType();
	}
	return *this;
}

void Dog::makeSound(void) const
{
	std::cout << "Huf Huf, AAAUUUUUUUUU" << std::endl;
}
