#ifndef HUMANB_HPP
# define HUMANB_HPP
# include "Weapon.hpp"

class HumanB
{
	private:
		std::string name;
		int is_armed;
		Weapon *_weapon;
	public:
		HumanB(std::string _name);
		~HumanB(void);
		void set_weapon(Weapon &_weapon);
		void attack(void);
};

#endif
