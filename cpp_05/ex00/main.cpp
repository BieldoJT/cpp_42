#include "Bureaucrat.hpp"

int main()
{
	try{
		Bureaucrat teste("EU", 2);
		Bureaucrat teste2("tu", -2);
		Bureaucrat teste3("eles", 200);
	}
	 catch (std::exception &e)
    {
        std::cout << "Peguei uma excecao ao criar Bureaucrat: "
                  << e.what() << std::endl;
    }
	/*
	std::cout << teste.getName() << std::endl;
	std::cout << teste2.getName() << std::endl;
	std::cout << teste3.getName() << std::endl;
	*/
}
