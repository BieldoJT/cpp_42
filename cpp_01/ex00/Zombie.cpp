#include "Zombie.hpp"

Zombie::Zombie(void)
{
	name = "teste";
	std::cout << "Zombie created" << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "Zombie destroied" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}
