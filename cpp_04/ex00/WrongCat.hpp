#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"


class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(WrongCat const &copy);
		~WrongCat();
		WrongCat &operator=(WrongCat const &copy);
		void makeSound() const;
};

#endif
