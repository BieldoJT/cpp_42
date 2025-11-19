#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat A("A", 2);
	Bureaucrat B("B", 1);
	Bureaucrat C("C", 150);
	try{


		A.incrementGrade();
		std::cout << A << std::endl;

		B.decrementGrade();
		std::cout << B << std::endl;

		C.decrementGrade();
		std::cout << C << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Peguei uma excecao : "
			<< e.what() << std::endl;
	}
}
