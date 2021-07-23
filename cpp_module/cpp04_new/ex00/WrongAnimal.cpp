#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	this->type = "none";
	std::cout << "!! New Wrong Animal !!" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "!! Wroung Animal Bye !!" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const& origin)
{
	*this = origin;
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal const& origin)
{
	this->type = origin.type;
	return (*this);
}

std::string WrongAnimal::getType() const
{
	return (this->type);
}

void WrongAnimal::makeSound() const
{
	std::cout << "* WRONG ANIMAL TYPE IS EMPTY *" << std::endl;
}

