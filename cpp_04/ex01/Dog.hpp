#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain* _brain;
	public:
		Dog();
		~Dog();
		Dog(Dog const &copy);
		Dog &operator=(Dog const &copy);
		Brain &getBrain(void) const;
		void setBrain(Brain const &brain);

		void makeSound(void) const;
};

#endif
