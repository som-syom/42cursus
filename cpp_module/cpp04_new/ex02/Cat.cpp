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
	*this = origin;
}

Cat& Cat::operator=(Cat const& origin)
{
	if (this->b)
		delete this->b;
	this->type = origin.type;
	this->b = origin.b;
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "* Myaoooo~~~ *" << std::endl;
}
