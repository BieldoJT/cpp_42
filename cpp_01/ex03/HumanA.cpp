#include "HumanA.hpp"

HumanA::HumanA(std::string _name, Weapon &weapon): _weapon(weapon)
{
	name = _name;
	std::cout << "Human A " << name << "created with weapon "<< _weapon.get_type() << std::endl;
}

HumanA::~HumanA()
{
	std::cout << "Human A "<< name << " destroyed" << std::endl;
}

void HumanA::attack(void)
{
	std::cout << name << " attacks with their " << _weapon.get_type() << std::endl;
	//https://github.com/tblaase/CPP-Module-01/blob/main/ex03/src/HumanB.cpp pra eu me basear
}
