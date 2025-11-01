#ifndef ZOMBIE_H
# define ZOMBIE_H
# include <iostream>
# include <string>

class Zombie
{
	private:
		std::string name;

	public:
		Zombie(void);
		Zombie(std::string _name);
		~Zombie(void);
		void announce(void);
		void put_name(std::string _name);
};

Zombie* zombieHorde(int N, std::string name );

#endif

