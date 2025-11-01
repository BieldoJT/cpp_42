#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <iostream>
# include <string>

class Weapon
{
	private:
		std::string type;
	public:
		//contructors
		Weapon(void);
		Weapon(const std::string& _type);
		//destructor
		~Weapon(void);
		//getters and setters
		std::string get_type() const;
		void set_type(std::string& _type);
};

#endif
