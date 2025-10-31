#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
	Zombie* new_zombie = new Zombie();
	new_zombie->name = name;
	return new_zombie;

}
