#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("Default"), _grade(150){}

Bureaucrat::Bureaucrat(std::string const name, int const note)
	: _name(name), _grade(note)
{
	try
	{
		if (note < 1)
			throw GradeTooHighException();
		if (note > 150)
			throw GradeTooLowException();
		std::cout << "Bureaucrat " << name <<  " created" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Failed to create Bureaucrat "<< name <<": " << e.what() << std::endl;
		throw;
	}
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat " << this->_name <<" destroyed" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy): _name(copy._name), _grade(copy.getGrade()){}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &copy)
{
	if(this != &copy)
	{
		// _name is const and cannot be reassigned, so I only copy the grade
		this->_grade = copy.getGrade();
	}
	return *this;
}

std::string Bureaucrat::getName() const
{
	return this->_name;
}

int Bureaucrat::getGrade() const
{
	return this->_grade;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

void Bureaucrat::incrementGrade()
{
	try
	{
		if(this->_grade == 1)
			throw GradeTooHighException();
		else
			this->_grade--;
	}
	catch(std::exception &e)
	{
		std::cerr << "Failed to increment Bureaucrat "<< this->_name <<" grade: " << e.what() << std::endl;
		throw;
	}
}

void Bureaucrat::decrementGrade()
{
	try
	{
		if(this->_grade == 150)
			throw GradeTooLowException();
		else
			this->_grade++;
	}
	catch (std::exception &e)
	{
		std::cerr << "Failed to decrement Bureaucrat "<< this->_name <<" grade: " << e.what() << std::endl;
		throw;
	}

}

std::ostream& operator<<(std::ostream& out, Bureaucrat &obj)
{
	out << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return out;
}

