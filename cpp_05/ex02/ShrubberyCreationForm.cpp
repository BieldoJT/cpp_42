#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyForm", false,  145, 137) ,_target("Default Target")
{

}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyForm", false, 145, 137) , _target(target)
{
	/*
	this->printStatus();
	std::cout << "Target: " << this->_target << std::endl;
	*/
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy): AForm(copy), _target(copy._target)
{
	*this = copy;
}


ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if(this != &other)
	{
		this->_target = other._target;
		this->setIsSigned(other.getIsSigned());
	}

	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}


void ShrubberyCreationForm::action() const
{
	std::ofstream archive((this->_target + std::string("_shrubbery")).c_str());

	if(archive)
	{
		archive << "                                                         ." << std::endl;
		archive << "                                              .         ;" << std::endl;
		archive << "                 .              .              ;%     ;;" << std::endl;
		archive << "                   ,           ,                :;%  %;" << std::endl;
		archive << "                    :         ;                   :;%;'     .," << std::endl;
		archive << "           ,.        %;     %;            ;        %;'    ,;" << std::endl;
		archive << "             ;       ;%;  %%;        ,     %;    ;%;    ,%'" << std::endl;
		archive << "              %;       %;%;      ,  ;       %;  ;%;   ,%;'" << std::endl;
		archive << "               ;%;      %;        ;%;        % ;%;  ,%;'" << std::endl;
		archive << "                `%;.     ;%;     %;'         `;%%;.%;'" << std::endl;
		archive << "                 `:;%.    ;%%. %@;        %; ;@%;%'" << std::endl;
		archive << "                    `:%;.  :;bd%;          %;@%;'" << std::endl;
		archive << "                      `@%:.  :;%.         ;@@%;'" << std::endl;
		archive << "                        `@%.  `;@%.      ;@@%;" << std::endl;
		archive << "                          `@%%. `@%%    ;@@%;" << std::endl;
		archive << "                            ;@%. :@%%  %@@%;" << std::endl;
		archive << "                              %@bd%%%bd%%:;" << std::endl;
		archive << "                                #@%%%%%:;;" << std::endl;
		archive << "                                %@@%%%::;" << std::endl;
		archive << "                                %@@@%(o);  . '" << std::endl;
		archive << "                                %@@@o%;:(.,'" << std::endl;
		archive << "                            `.. %@@@o%::;" << std::endl;
		archive << "                               `)@@@o%::;" << std::endl;
		archive << "                                %@@(o)::;" << std::endl;
		archive << "                               .%@@@@%::;" << std::endl;
		archive << "                               ;%@@@@%::;." << std::endl;
		archive << "                              ;%@@@@%%:;;;." << std::endl;
		archive << "                          ...;%@@@@@%%:;;;;,.." << std::endl;

		archive.close();
	}
	else
		throw ShrubberyCreationForm::FileCreationException();
}

const char *ShrubberyCreationForm::FileCreationException::what() const throw()
{
	return ("Failed to create and write on file!");
}






