
#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain* _brain;
	public:
		Cat();
		~Cat();
		Cat(Cat const &copy);
		Cat &operator=(Cat const &copy);

		Brain &getBrain(void) const;
		void setBrain(Brain const &brain);

		void makeSound(void) const;
};

#endif
