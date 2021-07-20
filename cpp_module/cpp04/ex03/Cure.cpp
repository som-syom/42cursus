#include "Cure.hpp"

Cure::Cure()
{
	this->_type = "cure";
	this->_xp = 0;
}

Cure::~Cure()
{

}

Cure::Cure(Cure const& origin)
{
	*this = origin;
}

Cure& Cure::operator=(Cure const& origin)
{
	this->_type = origin._type;
	this->_xp = origin._xp;
	return (*this);
}

AMateria* Cure::clone() const
{
	Cure *new_c = new Cure(*this);
	return (new_c);
}

void Cure::use(ICharacter& target)
{
	this->_xp +=10;
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

