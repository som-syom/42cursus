#include "Wind.hpp"

Wind::Wind()
{
	this->_type = "wind";
	this->_xp = 0;
}

Wind::~Wind()
{
	std::cout << "wind bye ~" << std::endl;
}

Wind::Wind(Wind const& origin)
{
	*this = origin;
}

Wind& Wind::operator=(Wind const& origin)
{
	this->_type = origin._type;
	this->_xp = origin._xp;
	return (*this);
}

AMateria* Wind::clone() const
{
	Wind *new_w = new Wind(*this);
	return (new_w);
}

void Wind::use(ICharacter& target)
{
	this->_xp += 10;
	std::cout << "* shoot an windstorm at " << target.getName() << " *" << std::endl;
}

