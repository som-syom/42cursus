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
	this->b = 0;
	*this = origin;
}

Dog& Dog::operator=(Dog const& origin)
{
	this->type = origin.type;
	this->b = new Brain(*origin.b);
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "* Wang!! Wang!! *" << std::endl;
}

void Dog::setIdea(int idx, std::string const& idea)
{
	this->b->setIdea(idx, idea);
}

std::string Dog::getIdea(int idx)
{
	return (this->b->getIdea(idx));
}

