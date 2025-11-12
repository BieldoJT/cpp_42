#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	std::cout << "WrongCat created" << std::endl;
	this->_type = "WrongCat";
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destroyed" << std::endl;
}

WrongCat::WrongCat(WrongCat const &copy) : WrongAnimal(copy)
{
	*this = copy;
}

WrongCat &WrongCat::operator=(WrongCat const &copy)
{
	if (this != &copy)
	{
		this->_type = copy.getType();
	}
	return *this;
}


void WrongCat::makeSound(void) const
{
	std::cout << "MIIIIIAAUUUUUUUUUUUUUU!" << std::endl;
}
