#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP


# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:
		bool _is_guarding;
	public:
		ScavTrap();
		~ScavTrap();
		ScavTrap(std::string const &name);
		ScavTrap(ScavTrap const &copy);
		ScavTrap &operator=(ScavTrap const &copy);
		void attack(const std::string& target);

		void guardGate();
};

#endif
