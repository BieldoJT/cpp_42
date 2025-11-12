#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>


class Animal
{
	protected:
		std::string _type;
	public:
		Animal();
		virtual ~Animal();
		Animal(Animal const &copy);
		Animal &operator=(Animal const &copy);

		void setType(std::string &type);

		std::string getType(void) const;

		virtual void makeSound(void) const; //adding 'vitual' make it able to override the function
};

#endif
