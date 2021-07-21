#include "Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	this->b = new Brain;
	std::cout << "!! New Dog !!" << std::endl;
}

Dog::~Dog()
{
	delete this->b;
	std::cout << "!! Dog Bye !!" << std::endl;
}

Dog::Dog(Dog const& origin)
{
	*this = origin;
}

Dog& Dog::operator=(Dog const& origin)
{
	this->type = origin.type;
	this->b = origin.b;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "* Wang!! Wang!! *" << std::endl;
}
