#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm(NULL, false,  145, 137)
{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
 : AForm(target, false, 145, 137)
{
	//criar o arquivo {target}_shrubbery
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy): _target(copy._target)
{}


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
