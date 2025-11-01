#include "Zombie.hpp"


Zombie* zombieHorde(int N, std::string name )
{
	if(N < 1)
		std::cout <<"The nmst be higher then 1!"<< std::endl;

	Zombie* horde = new Zombie[N];
	if(!horde);
		std::cout << "Error on allocation" << std::endl;
	int i = 0;
	while( i <= N)
	{
		horde[N].put_name(name);
		i++;
	}
	return horde;
}




