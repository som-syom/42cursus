#include "Ice.hpp"

Ice::Ice()
{
	this->_type = "ice";
	this->_xp = 0;
}

Ice::~Ice()
{

}

Ice::Ice(Ice const& origin)
{
	*this = origin;
}

Ice& Ice::operator=(Ice const& origin)
{
	this->_type = origin._type;
	this->_xp = origin._xp;
	return (*this);
}

AMateria* Ice::clone() const
{
	Ice *new_i = new Ice(*this);
	return (new_i);
}

void Ice::use(ICharacter& target)
{
	this->_xp += 10;
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}


