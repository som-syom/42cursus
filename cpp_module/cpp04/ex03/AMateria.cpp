#include "AMateria.hpp"

AMateria::AMateria()
{
	this->_type = "none";
	this->_xp = 0;
}

AMateria::AMateria(std::string const& type)
{
	this->_type = type;
	this->_xp = 0;
}

AMateria::~AMateria()
{

}

AMateria::AMateria(AMateria const& origin)
{
	*this = origin;
}

AMateria& AMateria::operator=(AMateria const& origin)
{
	this->_type = origin._type;
	this->_xp = origin._xp;
	return (*this);
}

std::string const& AMateria::getType() const
{
	return (this->_type);
}

unsigned int AMateria::getXP() const
{
	return (this->_xp);
}

void AMateria::use(ICharacter& target)
{
	this->_xp += 10;
}
