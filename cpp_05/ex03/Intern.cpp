#include "Intern.hpp"

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


Intern::Intern(void)
{
	std::cout << "Intern created" << std::endl;
}

Intern::Intern(const Intern &copy)
{
	*this = copy;
}

Intern &Intern::operator=(const Intern &other)
{
	if(this != &other)
	{
		(void) other;
	}
	return *this;
}

Intern::~Intern(void)
{
	std::cout << "Intern destroyed" << std::endl;
}


AForm *Intern::makeForm(std::string form_name, std::string target)
{
	int i =0;
	std::string forms[] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	while (i<3 && form_name != forms[i])
		i++;

	switch (i)
	{
	case (0):
		std::cout << "Intern creates ShrubberyCreationForm" << std::endl;
		return new ShrubberyCreationForm(target);
		break;
	case (1):
		std::cout << "Intern creates RobotomyRequestForm" << std::endl;
		return new RobotomyRequestForm(target);
		break;
	case (2):
		std::cout << "Intern creates PresidentialPardonForm" << std::endl;
		return new PresidentialPardonForm(target);
		break;
	default:
		std::cout << "The form "<< form_name<< " don't exists" << std::endl;
		throw FormNotExistsException();
	}


}

const char* Intern::FormNotExistsException::what() const throw()
{
	return "Form name dont't exists";
}
