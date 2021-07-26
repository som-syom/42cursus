#include "Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	this->b = new Brain;
	std::cout << "!! New Cat !!" << std::endl;
}

Cat::~Cat()
{
	delete this->b;
	std::cout << "!! Cat Bye !!" << std::endl;
}

Cat::Cat(Cat const& origin)
{
	this->b = 0;
	*this = origin;
}

Cat& Cat::operator=(Cat const& origin)
{
	this->type = origin.type;
	this->b = new Brain(*origin.b);
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "* Myaoooo~~~ *" << std::endl;
}
