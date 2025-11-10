#include "Cat.hpp"


Cat::Cat(void)
{
	std::cout << "Cat created" << std::endl;
	this->_type = "cat";
}

Cat::~Cat()
{
	std::cout << "Cat destroyed" << std::endl;
}

Cat::Cat(Cat const &copy) : Animal(copy)
{
	*this = copy;
}

Cat &Cat::operator=(Cat const &copy)
{
	if (this != &copy)
	{
		this->_type = copy.getType();
	}
	return *this;
}


void Cat::makeSound(void) const
{
	std::cout << "MIIIIIAAUUUUUUUUUUUUUU!" << std::endl;
}
