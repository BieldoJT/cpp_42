#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyForm", false,  145, 137) ,_target("Default Targert")
{

}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyForm", false, 145, 137) , _target(target)
{
	this->printStatus();
	std::cout << "Target: " << this->_target << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy): _target(copy._target)
{

}


ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if(this != &other)
	{
		this->_target = other._target;
	}

	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}


void ShrubberyCreationForm::action() const
{
	std::cout << "Criei" << std::endl;
}



