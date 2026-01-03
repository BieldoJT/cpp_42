#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

int main()
{
	Bureaucrat a("Ana",2);
	Bureaucrat b("kamila", 1);
	ShrubberyCreationForm shushu("Eu");
	ShrubberyCreationForm teste("algo");

	std::cout << shushu << std::endl;
	a.signForm(shushu);

	shushu.execute(b);
	//teste.execute(b);

	a.executeForm(shushu);
	shushu.signForm();
	std::cout << shushu << std::endl;
}
