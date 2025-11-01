#include "Zombie.hpp"

int main(void)
{
	Zombie *zombie = newZombie("New Zombie");
	zombie->announce();
	randomChump("Ramdom zombie");
	delete zombie;
	return 0;

}
