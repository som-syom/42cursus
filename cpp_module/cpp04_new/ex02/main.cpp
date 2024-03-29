#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	// Animal test;

	delete j;//should not create a leak
	delete i;
	std::cout << "---------------------" << std::endl;

	Dog *d1 = new Dog();
	Dog *d2 = new Dog(*d1);

	std::cout << d2->getType() << std::endl;

	delete d1;
	delete d2;

}