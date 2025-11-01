#include "Zombie.hpp"


Zombie* zombieHorde(int N, std::string name )
{
	if(N < 1)
	{
		std::cout <<"The number of zumbies must be higher then 1!"<< std::endl;
		return NULL;
	}

	Zombie* horde = new Zombie[N];
	if(!horde)
		std::cout << "Error on allocation" << std::endl;
	int i = 0;
	while( i < N)
	{
		horde[i].put_name(name);
		i++;
	}
	return horde;
}




