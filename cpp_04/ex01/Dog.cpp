#include "Dog.hpp"

Dog::Dog()
{
	this->_type = "dog";
	this->_brain = new Brain();
	std::cout << "Dog created" << std::endl;
}

Dog::~Dog()
{
	delete this->_brain;
	std::cout << "Dog destroyed" << std::endl;
}

Dog::Dog(Dog const &copy) : Animal(copy)
{
	this->_type = copy.getType();
	this->_brain = new Brain();
	*this->_brain = *copy._brain;
}

Dog &Dog::operator=(Dog const &copy)
{
	if (this != &copy)
	{
		this->_type = copy.getType();
		*this->_brain = *copy._brain;
	}
	return *this;
}

Brain &Dog::getBrain(void) const
{
	return (*this->_brain);
}

void	Dog::setBrain(Brain const &brain)
{
	*this->_brain = brain;
}

void Dog::makeSound(void) const
{
	std::cout << "Huf Huf, AAAUUUUUUUUU" << std::endl;
}
