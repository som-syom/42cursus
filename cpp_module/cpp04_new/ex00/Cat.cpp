#include "Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	std::cout << "!! New Cat !!" << std::endl;
}

Cat::~Cat()
{
	std::cout << "!! Cat Bye !!" << std::endl;
}

Cat::Cat(Cat const& origin)
{
	*this = origin;
}

Cat& Cat::operator=(Cat const& origin)
{
	this->type = origin.type;
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "* Myaoooo~~~ *" << std::endl;
}
