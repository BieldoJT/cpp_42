#ifndef INTERN_HPP
# define INTERN_HPP

# include <exception>
# include "AForm.hpp"


class AForm;

class Intern
{
	public:
		Intern(void);
		Intern(const Intern &copy);
		Intern &operator=(const Intern &other);
		~Intern(void);

		AForm *makeForm(std::string form_name, std::string target);

		class FormNotExistsException : public std::exception
		{
			virtual const char* what() const throw();
		};

};



#endif
