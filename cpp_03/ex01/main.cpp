#include "ScavTrap.hpp"

void	thomas_rundown(void)
{
	ScavTrap thomas("Thomas");

	thomas.attack("Bob");
	thomas.attack("Diana");
	thomas.attack("Elisa");
	thomas.attack("Fred");
	thomas.attack("Gemma");
	thomas.attack("Henry");
	thomas.attack("Isabella");
	thomas.attack("Jack");
	thomas.attack("Kevin");
	thomas.attack("Laura");
	thomas.attack("Mike");
}

void	lucas_rundown(void)
{
	ScavTrap lucas("Lucas");

	lucas.guardGate();
}

void	bob_rundown(void)
{
	ScavTrap bob("Bob");

	while (bob.getHitPoints())
	{
		bob.takeDamage(20);
		bob.beRepaired(10);
	}
	bob.takeDamage(1);
}

int	main(void)
{
	std::cout << std::endl << std::endl << "Performing Thomas's rundown..." << std::endl << std::endl;
	thomas_rundown();
	std::cout << std::endl << std::endl << "Performing Bob's rundown..." << std::endl << std::endl;
	bob_rundown();
	std::cout << std::endl << std::endl << "Performing Lucas's rundown..." << std::endl << std::endl;
	lucas_rundown();
}
