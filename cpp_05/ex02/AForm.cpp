#include "AForm.hpp"



AForm::AForm() : _name("Default"), _isSigned(false),_requiredGrade(150) ,_executeGrade(150){}

AForm::AForm(std::string name, bool is_signed, int required_grade, int execute_grade) :_name(name), _requiredGrade(required_grade), _executeGrade(execute_grade)
{
	try
	{
		if(required_grade > 150 || execute_grade > 150)
			throw GradeTooLowException();
		if(required_grade < 1 || required_grade < 1)
			throw GradeTooHighException();
		this->_isSigned = is_signed;
		std::cout << "Form "<< name <<" created" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr <<"Failed to create form: "<< e.what() << std::endl;
		throw;
	}
}

AForm::AForm(AForm const &copy)
: _name(copy._name),
_isSigned(copy._isSigned),
_requiredGrade(copy._requiredGrade),
_executeGrade(copy._executeGrade)
{}

AForm &AForm::operator=(AForm const &copy)
{
	if(this != &copy)
	{
		this->_isSigned = copy._isSigned;
	}
	return *this;
}

AForm::~AForm(){
	std::cout << "Form "<< this->getName() <<" destroyed" << std::endl;
}

std::string AForm::getName()
{
	return this->_name;
}

bool AForm::getIsSigned()
{
	return this->_isSigned;
}

int AForm::getRequireGrade() const
{
	return this->_requiredGrade;
}

int AForm::getExecuteGrade() const
{
	return this->_executeGrade;
}

void AForm::printStatus()
{
	std::cout << "Name: " << this->getName() << std::endl <<
	"Require Grade: " << this->getRequireGrade() << std::endl <<
	"Execution Grade: " << this->getExecuteGrade() << std::endl <<
	"is signed?: " << this->getIsSigned() << std::endl;
}

void AForm::signForm()
{
	this->_isSigned = true;
}

void AForm::beSigned(Bureaucrat const &bureaucrat)
{
	if(bureaucrat.getGrade() > this->getRequireGrade())
		throw GradeTooLowException();
	this->signForm();
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

std::ostream &operator<<(std::ostream &out , AForm &obj)
{
	out << "Form name: " << obj.getName() << std::endl
	<< "is signed: " << obj.getIsSigned() << std::endl
	<< "required grade: " << obj.getRequireGrade() << std::endl
	<< "execution grade: " << obj.getExecuteGrade() << std::endl;
	return out;
}
