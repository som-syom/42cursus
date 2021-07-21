#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	this->type = "Wrong Cat";
	std::cout << "!! New Wrong Cat !!" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "!! Wrong Cat Bye !!" << std::endl;
}

WrongCat::WrongCat(WrongCat const& origin)
{
	*this = origin;
}

WrongCat& WrongCat::operator=(WrongCat const& origin)
{
	this->type = origin.type;
	return (*this);
}

void WrongCat::makeSound() const
{
	std::cout << "* Wroooooooong~ *" << std::endl;
}
