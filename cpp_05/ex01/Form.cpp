#include "Form.hpp"



Form::Form() : _name("Default"), _isSigned(false),_requiredGrade(150) ,_executeGrade(150){}

Form::Form(std::string name, bool is_signed, int required_grade, int execute_grade) :_name(name), _requiredGrade(required_grade), _executeGrade(execute_grade)
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

Form::Form(Form const &copy)
: _name(copy._name),
_isSigned(copy._isSigned),
_requiredGrade(copy._requiredGrade),
_executeGrade(copy._executeGrade)
{}

Form &Form::operator=(Form const &copy)
{
	if(this != &copy)
	{
		this->_isSigned = copy._isSigned;
	}
	return *this;
}

Form::~Form(){
	std::cout << "Form "<< this->getName() <<" destroyed" << std::endl;
}

std::string Form::getName()
{
	return this->_name;
}

bool Form::getIsSigned()
{
	return this->_isSigned;
}

int Form::getRequireGrade() const
{
	return this->_requiredGrade;
}

int Form::getExecuteGrade() const
{
	return this->_executeGrade;
}

void Form::signForm()
{
	this->_isSigned = true;
}

void Form::beSigned(Bureaucrat const &bureaucrat)
{
	if(bureaucrat.getGrade() > this->getRequireGrade())
		throw GradeTooLowException();
	this->signForm();
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

std::ostream &operator<<(std::ostream &out , Form &obj)
{
	out << "Form name: " << obj.getName() << std::endl
	<< "is signed: " << obj.getIsSigned() << std::endl
	<< "required grade: " << obj.getRequireGrade() << std::endl
	<< "execution grade: " << obj.getExecuteGrade() << std::endl;
	return out;
}
