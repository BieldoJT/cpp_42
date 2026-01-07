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
		virtual void action() const = 0;

	public:
		AForm();
		AForm(std::string name, bool is_signed, int required_grade, int execute_grade);
		AForm(AForm const &copy);
		AForm &operator=(AForm const &copy);
		~AForm();

		//getters
		std::string getName();
		bool getIsSigned() const;
		void setIsSigned(bool is_Signed);
		int getRequireGrade() const;
		int getExecuteGrade() const;
		void printStatus();
		void signForm();
		void beSigned(Bureaucrat const &bureaucrat);

		void execute(Bureaucrat const &executor) const;







		class GradeTooHighException : public std::exception
		{
			virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			virtual const char* what() const throw();
		};

		class IsNotSignedException : public std::exception
		{
			virtual const char* what() const throw();
		};


};

std::ostream &operator<<(std::ostream &out, AForm &obj);

#endif
