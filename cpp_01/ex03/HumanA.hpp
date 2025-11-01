#ifndef HUMANA_HPP
# define HUMANA_HPP
# include "Weapon.hpp"

class HumanA
{
	private:
		std::string name;
		Weapon &_weapon;
	public:
		//contructor e desctructor
		HumanA(std::string _name, Weapon &weapon);
		~HumanA(void);

		//getter and setter
		//method
		void attack(void);
};
#endif
