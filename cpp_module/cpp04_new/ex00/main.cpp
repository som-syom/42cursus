#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;

	std::cout << "--------------------" << std::endl;
	WrongAnimal* w1 = new WrongAnimal;
	WrongAnimal* w2 = new WrongCat;

	std::cout << w1->getType() << " " << std::endl;
	std::cout << w2->getType() << " " << std::endl;
	w1->makeSound();
	w2->makeSound();

	delete w1;
	delete w2;
}