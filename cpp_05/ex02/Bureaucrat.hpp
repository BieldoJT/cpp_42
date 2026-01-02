#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <exception>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		std::string const _name;
		int _grade;
	public:
		//execpitons
		class GradeTooHighException : public std::exception{
			virtual const char* what() const throw(); //the throw means no expect
		};
		class GradeTooLowException : public std::exception{
			virtual const char* what() const throw();
		};
		//constructurs and destructor
		Bureaucrat();
		Bureaucrat(std::string name, int const note);
		~Bureaucrat();
		Bureaucrat(Bureaucrat const &copy);
		Bureaucrat &operator=(Bureaucrat const &copy);

		//getters
		std::string getName() const;
		int getGrade() const;

		//other methods
		void incrementGrade();
		void decrementGrade();

		void signForm(AForm &form);

	};

std::ostream &operator<<(std::ostream &out, Bureaucrat &obj);

#endif




