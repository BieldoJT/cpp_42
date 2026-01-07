#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <unistd.h>

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm",false, 72,45), _target("Default target")
{}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm",false, 72,45), _target(target)
{
	std::cout << "Form created with target "<< _target << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy), _target(copy._target)
{
	*this = copy;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if(this != &other)
	{
		this->_target = other._target;
		this->setIsSigned(other.getIsSigned());
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{}

void RobotomyRequestForm::action() const
{
	std::cout << "buzzz...!!!" << std::endl;
	usleep(100000);
	std::cout << "buzz...!!" << std::endl;
	usleep(100000);
	std::cout << "zzzzzzzz...!!" << std::endl;
	usleep(100000);
	std::cout << "buzz..!" << std::endl;
	usleep(100000);


	int random_int = std::rand() % 2;

	if(random_int == 1)
		std::cout << "The " << this->_target << " has been robotomized! 🤖" << std::endl;
	else
		std::cout << "The robotomy failed! ❌" << std::endl;
}
