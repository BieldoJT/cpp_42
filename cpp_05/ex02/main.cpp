#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

int main()
{
	Bureaucrat a("Ana",2);
	Bureaucrat b("kamila", 1);
	ShrubberyCreationForm shushu("Eu");
	ShrubberyCreationForm teste("algo");

	std::cout << "PRimeiro printt\n";
	std::cout << shushu << std::endl;
	a.signForm(shushu);
	std::cout << shushu << std::endl;
	shushu.execute(b);

	teste = shushu;
	teste.execute(b);
	std::cout << teste << std::endl;
}
