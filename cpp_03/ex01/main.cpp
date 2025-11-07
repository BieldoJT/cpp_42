#include "ScavTrap.hpp"

void	thomas_rundown(void)
{
	ScavTrap thomas("Thomas");
	ClapTrap alice("Alice");

	thomas.attack("Bob");
	alice.attack("Diana");
	thomas.attack("Elisa");
	alice.attack("Fred");
	thomas.attack("Gemma");
	alice.attack("Henry");

}

void	lucas_rundown(void)
{
	ScavTrap lucas("Lucas");
	ScavTrap daniel("Daniel");
	ClapTrap jason("Jason");
	lucas.guardGate();
	lucas.status();
	daniel.status();

	jason = daniel;
	jason.attack("Someone");


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
