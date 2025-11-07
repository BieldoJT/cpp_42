#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>
# include <string>


class ClapTrap
{
	protected:
		std::string _name;
		int _hitPoints;
		int _energyPoints;
		int _attackDamage;

	public:
		ClapTrap(void);
		ClapTrap(std::string const &name);
		~ClapTrap(void);
		ClapTrap(ClapTrap const &copy);
		ClapTrap &operator=(ClapTrap const &copy);

		void setName(std::string name);
		void setHitPoints(unsigned int num);
		void setEnergyPoints(unsigned int num);
		void setAttackDamage(unsigned int num);

		std::string getName();
		int getHitPoints();
		int getEnergyPoints();
		int getAttackDamage();




		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

};



#endif
