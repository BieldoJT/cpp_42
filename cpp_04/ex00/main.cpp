#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "Printing contructurs:" << std::endl << std::endl;
	const Animal* meta = new Animal();
	const WrongAnimal* mita = new WrongAnimal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	const WrongAnimal* wrongCat = new WrongCat();

	std::cout << std::endl << "Printing types:" << std::endl << std::endl;
	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	std::cout << wrongCat->getType() << " " << std::endl << std::endl;


	std::cout<< std::endl << "Printing sounds:" << std::endl << std::endl;
	std::cout << "Right sounds:" << std::endl;
	meta->makeSound();
	dog->makeSound(); // will output the dog sound!
	cat->makeSound();
	std::cout << "Wrong sounds:" << std::endl;
	mita->makeSound();
	wrongCat->makeSound();

	std::cout<< std::endl << "Printing destructurs:" << std::endl << std::endl;
	delete dog;
	delete cat;
	delete meta;
	delete wrongCat;
	delete mita;
	return 0;
}
