#include "FragTrap.hpp"


FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap from ClapTrap created" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(std::string const &name) : ClapTrap(name)
{
	std::cout << "FragTrap " <<name<< " from ClapTrap created"  << std::endl;
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " <<this->_name<< " from ClapTrap destroyed" << std::endl;
}

FragTrap::FragTrap(FragTrap const &copy) : ClapTrap(copy){}

FragTrap &FragTrap::operator=(FragTrap const &copy)
{
	if (this != &copy)
	{
		this->_name = copy._name;
		this->_hitPoints = copy._hitPoints;
		this->_energyPoints = copy._energyPoints;
		this->_attackDamage = copy._attackDamage;
	}
	std::cout << "Assigment operator called!!!" << std::endl;
	return *this;
}


void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << this->_name << " says:" << std::endl
	<< "LET'S HIGH FIVE!!!!" << std::endl;
}
