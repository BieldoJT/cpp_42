#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonForm", false,  25, 5) ,_target("Default Target")
{

}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", false, 25, 5) , _target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy): AForm(copy), _target(copy._target)
{
	*this = copy;
}


PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if(this != &other)
	{
		this->_target = other._target;
		this->setIsSigned(other.getIsSigned());
	}

	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{}


void PresidentialPardonForm::action() const
{
	std::cout <<"The " << this->_target << " has been pardoned by Zaphod Beeblebrox!!" << std::endl;
}
