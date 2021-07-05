#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->value = 0;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& origin)
{
	std::cout << "Copy constructor called" << std::endl;
	value = origin.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& origin)
{
	std::cout << "Assignation operator called" << std::endl;
	this->value = origin.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}
void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}
