#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
	// for the random number generator in robotomyform action, used to created a new sequence in diferend executions
	std::srand(std::time(0));
	Bureaucrat randomBureaucrat("Ana",25);
	AForm *rrf;
	Intern randomIntern;

	rrf = randomIntern.makeForm("robotomy request", "shushu");


	std::cout << *rrf << std::endl;
	std::cout << randomBureaucrat << std::endl;
	std::cout << "signning form:\n";
	randomBureaucrat.signForm(*rrf);
	std::cout << *rrf << std::endl;
	std::cout << "executing form:\n";
	randomBureaucrat.executeForm(*rrf);
	delete rrf;
}
