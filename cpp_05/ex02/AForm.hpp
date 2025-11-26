#ifndef AFORM_HPP
# define AFORM_HPP

# include <exception>
# include <string>
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		std::string const _name;
		bool _isSigned;
		int const _requiredGrade;
		int const _executeGrade;

	public:
		AForm();
		AForm(std::string name, bool is_signed, int required_grade, int execute_grade);
		AForm(AForm const &copy);
		AForm &operator=(AForm const &copy);
		~AForm();

		std::string getName();
		bool getIsSigned();
		int getRequireGrade() const;
		int getExecuteGrade() const;
		virtual void signForm() = 0;

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

std::ostream &operator<<(std::ostream &out, AForm &obj);

#endif
