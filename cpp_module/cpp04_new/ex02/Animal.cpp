#include "Animal.hpp"

Animal::Animal()
{
	this->type = "none";
	std::cout << "!! New Animal !!" << std::endl;
}

Animal::~Animal()
{
	std::cout << "!! Animal Bye !!" << std::endl;
}

Animal::Animal(Animal const& origin)
{
	*this = origin;
}

Animal& Animal::operator=(Animal const& origin)
{
	this->type = origin.type;
	return (*this);
}

std::string Animal::getType() const
{
	return (this->type);
}

