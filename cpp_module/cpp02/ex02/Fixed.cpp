#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->value = 0;
}

Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called" << std::endl;
	this->value = num << this->frac;
}

Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf(num * (1 << this->frac));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& origin)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = origin;
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

int Fixed::toInt(void) const
{
	return (this->value >> this->frac);
}

float Fixed::toFloat(void) const
{
	return ((float)this->value / (1 << this->frac));
}

Fixed& Fixed::operator=(const Fixed& origin)
{
	std::cout << "Assignation operator called" << std::endl;
	value = origin.value;
	return (*this);
}

bool Fixed::operator<(const Fixed& f)
{
	return (this->toFloat() < f.toFloat());
}

bool Fixed::operator>(const Fixed& f)
{
	return (this->toFloat() > f.toFloat());
}

bool Fixed::operator<=(const Fixed& f)
{
	return (this->toFloat() <= f.toFloat());
}

bool Fixed::operator>=(const Fixed& f)
{
	return (this->toFloat() >= f.toFloat());
}

bool Fixed::operator==(const Fixed& f)
{
	return (this->toFloat() == f.toFloat());
}

bool Fixed::operator!=(const Fixed& f)
{
	return (this->toFloat() != f.toFloat());
}

float Fixed::operator+(const Fixed& f)
{
	return (this->toFloat() + f.toFloat());
}

float Fixed::operator-(const Fixed& f)
{
	return (this->toFloat() - f.toFloat());
}

float Fixed::operator*(const Fixed& f)
{
	return (this->toFloat() * f.toFloat());
}

float Fixed::operator/(const Fixed& f)
{
	return (this->toFloat() / f.toFloat());
}

Fixed& Fixed::operator++()
{
	++(this->value);
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(this->toFloat());
	++(*this);
	return (tmp);
}

Fixed& Fixed::operator--()
{
	--(this->value);
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(this->toFloat());
	--(*this);
	return (tmp);
}

Fixed& Fixed::min(Fixed& f1, Fixed& f2)
{
	if (f1.toFloat() < f2.toFloat())
		return (f1);
	else
		return (f2);
}

Fixed& Fixed::max(Fixed& f1, Fixed& f2)
{
	if (f1.toFloat() > f2.toFloat())
		return (f1);
	else
		return (f2);
}

const Fixed& Fixed::min(const Fixed& f1, const Fixed& f2)
{
	if (f1.toFloat() < f2.toFloat())
		return (f1);
	else
		return (f2);
}

const Fixed& Fixed::max(const Fixed& f1, const Fixed& f2)
{
	if (f1.toFloat() > f2.toFloat())
		return (f1);
	else
		return (f2);
}

std::ostream& operator<<(std::ostream &out, const Fixed &f)
{
	out << f.toFloat();
	return (out);
}
