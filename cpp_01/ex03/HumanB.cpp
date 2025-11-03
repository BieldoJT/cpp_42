#include "HumanB.hpp"
HumanB::HumanB(std::string _name)
{
	name = _name;
	is_armed = 0;
	std::cout << "Human B " << name << " created" << std::endl;
}
HumanB::~HumanB(void)
{
	std::cout << "Human B " << name << " destroyed" << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
	is_armed = 1;
	std::cout <<"Human B " << name << " is armed with weapon " << _weapon->getType() << std::endl;
}

void HumanB::attack(void)
{
	std::cout << name << " attacks with their " << _weapon->getType() << std::endl;
}




