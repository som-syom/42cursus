#include "Fire.hpp"

Fire::Fire()
{
	this->_type = "fire";
	this->_xp = 0;
}

Fire::~Fire()
{
	std::cout << "fire bye ~" << std::endl;
}

Fire::Fire(Fire const& origin)
{
	*this = origin;
}

Fire& Fire::operator=(Fire const& origin)
{
	this->_type = origin._type;
	this->_xp = origin._xp;
	return (*this);
}

AMateria* Fire::clone() const
{
	Fire *new_f = new Fire(*this);
	return (new_f);
}

void Fire::use(ICharacter& target)
{
	this->_xp += 10;
	std::cout << "* shoots an fire ball at " << target.getName() << " *" << std::endl;
}

