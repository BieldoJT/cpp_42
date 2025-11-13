#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal Created" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destroyed" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &copy)
{
	*this = copy;
}



std::string WrongAnimal::getType(void) const
{
	return this->_type;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &copy)
{
	if(this != &copy)
	{
		this->_type = copy.getType();
	}
	return *this;
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "Generic WrongAnimal Sound" << std::endl;
}


