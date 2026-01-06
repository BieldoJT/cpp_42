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
	Bureaucrat a("Ana",4);
	PresidentialPardonForm shushu("UM TESTE");


	std::cout << shushu << std::endl;
	std::cout << a << std::endl;
	std::cout << "assinando o form:\n";
	a.signForm(shushu);
	std::cout << shushu << std::endl;
	std::cout << "executando o form:\n";
	shushu.execute(a);
}
