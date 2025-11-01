#include "Zombie.hpp"
#include <stdlib.h>

int main(int argc, char **argv)
{
	if (argc != 2)
		return 1;
	int num_zombies = atoi(argv[1]);
	Zombie *horde = zombieHorde(num_zombies, "Harold");
	if (!horde)
		return 1;
	for(int i = 0; i < num_zombies; i++)
	{
		horde[i].announce();
	}
	delete[] horde;
	return 0;
}
