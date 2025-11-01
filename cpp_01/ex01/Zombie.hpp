#ifndef ZOMBIE_H
# define ZOMBIE_H
# include <iostream>
# include <string>

class Zombie
{
	private:
		std::string name;

	public:
		Zombie();
		Zombie(std::string _name);
		~Zombie(void);
		void announce(void);
		void put_name(std::string name);
};

#endif

