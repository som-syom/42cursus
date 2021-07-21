#include "Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	std::cout << "!! New Dog !!" << std::endl;
}

Dog::~Dog()
{
	std::cout << "!! Dog Bye !!" << std::endl;
}

Dog::Dog(Dog const& origin)
{
	*this = origin;
}

Dog& Dog::operator=(Dog const& origin)
{
	this->type = origin.type;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "* Wang!! Wang!! *" << std::endl;
}
