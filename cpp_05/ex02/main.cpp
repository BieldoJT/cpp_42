#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
	// for the random number generator in robotomyform action, used to created a new sequence in diferend executions
	std::srand(std::time(0));
	Bureaucrat a("Ana",2);
	Bureaucrat b("kamila", 1);
	PresidentialPardonForm shushu("Eu");
	PresidentialPardonForm teste("algo");


	std::cout << "PRimeiro printt\n";
	std::cout << shushu << std::endl;
	a.signForm(shushu);
	std::cout << shushu << std::endl;
	shushu.execute(b);



	teste = shushu;
	//teste.execute(b);
	std::cout << teste << std::endl;
}
