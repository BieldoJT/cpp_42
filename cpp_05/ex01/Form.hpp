#ifndef FORM_HPP
# define FORM_HPP

# include <exception>
# include <string>
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string const _name;
		bool _isSigned;
		int const _requiredGrade;
		int const _executeGrade;

	public:
		Form();
		Form(std::string name, bool is_signed, int required_grade, int execute_grade);
		Form(Form const &copy);
		Form &operator=(Form const &copy);
		~Form();

		std::string getName();
		bool getIsSigned();
		int getRequireGrade() const;
		int getExecuteGrade() const;
		virtual void signForm();

		void beSigned(Bureaucrat const &bureaucrat);

		class GradeTooHighException : public std::exception
		{
			virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			virtual const char* what() const throw();
		};

};

std::ostream &operator<<(std::ostream &out, Form &obj);

#endif
