#include "RadScorpion.hpp"

RadScorpion::RadScorpion()
{
	this->type = "RadScorpion";
	this->hp = 80;
	std::cout << "* click click click *" << std::endl;
}

RadScorpion::~RadScorpion()
{
	std::cout << "* SPROTCH *" << std::endl;
}

RadScorpion::RadScorpion(RadScorpion const& origin)
{
	*this = origin;
}

RadScorpion& RadScorpion::operator=(RadScorpion const& origin)
{
	this->type = origin.type;
	this->hp = origin.hp;
	return (*this);
}

