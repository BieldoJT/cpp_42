#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat A("A", 50);
	Bureaucrat B("B", 1);
	Bureaucrat C("C", 125);
	Form teste1("Teste",false,25,10);
	Form teste2("Outro teste", false, 50,20);
	try{

		A.signForm(teste2);
		C.signForm(teste1);
	}
	catch (std::exception &e)
	{
		std::cout << "Peguei uma excecao : "
		<< e.what() << std::endl;
	}
	std::cout << teste2 << std::endl;
	std::cout << teste1 << std::endl;
}
