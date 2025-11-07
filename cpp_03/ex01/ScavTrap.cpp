#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	std::cout << "ScavTrap from ClapTrap created" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	this-> _is_guarding = false;
}

ScavTrap::ScavTrap(std::string const &name) : ClapTrap(name)
{
	std::cout << "ScavTrap " <<name<< " from ClapTrap created"  << std::endl;
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	this-> _is_guarding = false;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " <<this->_name<< " from ClapTrap destroyed" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &copy) : ClapTrap(copy)
{
	this->_is_guarding = copy._is_guarding;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &copy)
{
	if(this != &copy)
	{
		this->_name = copy._name;
		this->_hitPoints = copy._hitPoints;
		this->_energyPoints = copy._energyPoints;
		this->_attackDamage = copy._attackDamage;
		this->_is_guarding = copy._is_guarding;
	}
	std::cout << "Assigment operator called!!!" << std::endl;
	return *this;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->_name << " is now in Gate Keaper mode" << std::endl;
	this->_is_guarding = true;
}

void ScavTrap::status()
{
	if(this->_is_guarding)
		std::cout << "ScavTrap " << this->getName() << " is guarding!!" << std::endl;
	else
		std::cout << "ScavTrap " << this->getName() << " is doing nothing!!" << std::endl;
}


void ScavTrap::attack(const std::string& target)
{
	std::cout << "ScavTrap "<<this->getName()
	<<" attacks "<< target
	<<", causing "<<this->getAttackDamage()
	<<" points of damage!"<< std::endl;
	this->_energyPoints--;

}
