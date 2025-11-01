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
	std::cout <<"Weapon "<< this->get_type() << "is destroyed" << std::endl;
}

std::string Weapon::get_type() const
{
	return type;
}

void Weapon::set_type(std::string& _type)
{
	type = _type;
}
