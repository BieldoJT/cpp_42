#include "Cat.hpp"


Cat::Cat(void)
{
	this->_type = "cat";
	this->_brain = new Brain();
	std::cout << "Cat created" << std::endl;
}

Cat::~Cat()
{
	delete this->_brain;
	std::cout << "Cat destroyed" << std::endl;
}

Cat::Cat(Cat const &copy) : Animal(copy)
{
	this->_type = copy.getType();
	this->_brain = new Brain();
	*this->_brain = *copy._brain;

}

Cat &Cat::operator=(Cat const &copy)
{
	if (this != &copy)
	{
		this->_type = copy.getType();
		*this->_brain = *copy._brain;
	}
	return *this;
}

Brain &Cat::getBrain(void) const
{
	return (*this->_brain);
}

void	Cat::setBrain(Brain const &brain)
{
	*this->_brain = brain;
}


void Cat::makeSound(void) const
{
	std::cout << "MIIIIIAAUUUUUUUUUUUUUU!" << std::endl;
}
