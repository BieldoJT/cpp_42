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
		std::string getType() const;
		void setType(std::string _type);
};

#endif
