#include "Weapon.hpp"

Weapon::Weapon(void)
{
	type = "";
	std::cout << "Weapon created!" << std::endl;
}

Weapon::Weapon(const std::string& _type)
{
	type = _type;
	std::cout << "Weapon "<< type <<" created!" << std::endl;
}

Weapon::~Weapon(void)
{
	std::cout <<"Weapon "<< this->getType() << "is destroyed" << std::endl;
}

std::string Weapon::getType() const
{
	return type;
}

void Weapon::setType(std::string _type)
{
	type = _type;
}
