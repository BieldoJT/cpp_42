#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <exception>

class Bureaucrat
{
	private:
		std::string const _name;
		int _grade;
	public:
		Bureaucrat(std::string name, int const note);
		~Bureaucrat();
		std::string getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();

		class GradeTooHighException : public std::exception{};
		class GradeTooLowException : public std::exception{};

	};

std::ostream &operator<<(std::ostream &out, Bureaucrat &obj);

#endif




