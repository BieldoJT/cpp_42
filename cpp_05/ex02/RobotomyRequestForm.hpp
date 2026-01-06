#ifndef ROBOTOMYRESQUESTFORM_HPP
# define ROBOTOMYRESQUESTFORM_HPP


# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string _target;
		virtual void action() const;
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &copy);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
		~RobotomyRequestForm();
};

#endif
