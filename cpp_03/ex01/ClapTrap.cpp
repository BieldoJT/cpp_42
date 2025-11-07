#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	std::cout << "ClapTrap created" << std::endl;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
}

ClapTrap::ClapTrap(std::string const &name)
{
	std::cout << "ClapTrap " <<name<< " created"  << std::endl;
	this->_name = name;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap "<<this->_name<< " destroyed" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &copy)
{
	*this = copy;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &copy)
{
	if(this != &copy)
	{
		this->_name = copy._name;
		this->_hitPoints = copy._hitPoints;
		this->_energyPoints = copy._energyPoints;
		this->_attackDamage = copy._attackDamage;
	}
	std::cout << "Assigment operator called!!!" << std::endl;
	return *this;
}

void ClapTrap::setName(std::string name)
{
	this->_name = name;
}

void ClapTrap::setHitPoints(unsigned int num)
{
	this->_hitPoints = num;
}
void ClapTrap::setEnergyPoints(unsigned int num)
{
	this->_energyPoints= num;
}
void ClapTrap::setAttackDamage(unsigned int num)
{
	this->_attackDamage = num;
}

std::string ClapTrap::getName()
{
	return this->_name;
}
int ClapTrap::getHitPoints()
{
	return _hitPoints;
}
int ClapTrap::getEnergyPoints()
{
	return _energyPoints;
}

int ClapTrap::getAttackDamage()
{
	return this->_attackDamage;
}

void ClapTrap::attack(const std::string& target)
{
	std::cout << "ClapTrap "<<this->getName()
	<<" attacks "<< target
	<<", causing "<<this->getAttackDamage()
	<<" points of damage!"<< std::endl;
	this->_energyPoints--;

}
void ClapTrap::takeDamage(unsigned int amount)
{
	if(this->_hitPoints != 0)
	{
		std::cout << "ClapTrap "<<this->getName()
		<<" was attacked and took "<< amount
		<<" of damage."<< std::endl;
		this->_hitPoints-=amount;
	}
	else
		std::cout << "ClapTrap "<<this->getName() << " is dead!!" << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap "<<this->getName()
	<<" restored "<< amount
	<<" points of hit points." << std::endl;
	this->_hitPoints+=amount;
	this->_energyPoints--;
}
