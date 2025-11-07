#include "FragTrap.hpp"

void	thomas_rundown(void)
{
	FragTrap thomas("Thomas");

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
	FragTrap lucas("Lucas");
	FragTrap other("Other");

	lucas.highFivesGuys();
	other.highFivesGuys();
	other = lucas;
	lucas.highFivesGuys();
	other.highFivesGuys();
}

void	bob_rundown(void)
{
	FragTrap bob("Bob");
	FragTrap other(bob);

	std::cout << "This is other!!!!!!!!!!!" << std::endl;
	while (other.getHitPoints())
	{
		other.takeDamage(50);
		other.beRepaired(30);
	}
	other.takeDamage(1);
	std::cout << "This is Bob!!!!!!!!!!!!!!!!" << std::endl;
	while (bob.getHitPoints())
	{
		bob.takeDamage(50);
		bob.beRepaired(30);
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
