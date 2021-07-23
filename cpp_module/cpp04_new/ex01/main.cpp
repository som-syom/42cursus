#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;//should not create a leak
	delete i;

	std::cout << "---------------------[assingment test]" << std::endl;
	Dog basic;
	
	basic.setIdea(0, "42seoul");
	basic.setIdea(1, "Cardet");
	basic.setIdea(3, "dhyeon");
	basic.setIdea(5, "I like sushi");

	Dog tmp = basic;

	std::cout << tmp.getIdea(0) << std::endl;
	std::cout << tmp.getIdea(1) << std::endl;
	std::cout << tmp.getIdea(3) << std::endl;
	std::cout << tmp.getIdea(5) << std::endl;

	std::cout << "---------------------[copy test]" << std::endl;
	Dog* copy = new Dog(basic);

	std::cout << copy->getIdea(0) << std::endl;
	std::cout << copy->getIdea(1) << std::endl;
	std::cout << copy->getIdea(3) << std::endl;
	std::cout << copy->getIdea(5) << std::endl;

	basic.setIdea(7, "test");
	std::cout << copy->getIdea(7) << std::endl;

	std::cout << "---------------------[delete copy]" << std::endl;
	delete copy;

	std::cout << "---------------------[array]" << std::endl;
	Animal *arr[20];
	for(int i = 0; i < 20; i += 2)
	{
		arr[i] = new Dog;
		arr[i + 1] = new Cat;
	}

	std::cout << "---------------------[delete array]" << std::endl;
	for (int i = 0; i < 20; i++)
		delete arr[i];

	std::cout << "---------------------" << std::endl;
	return (0);
}