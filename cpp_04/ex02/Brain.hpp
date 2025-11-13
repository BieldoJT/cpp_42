#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include <iostream>



class Brain
{
	protected:
		std::string _ideas[100];
	public:
		Brain();
		Brain(Brain const &copy);
		~Brain();
		Brain &operator=(Brain const &copy);

		std::string const &getIdea(int const &index) const;
		void setIdea(std::string const &idea, int const &index);
};


#endif
