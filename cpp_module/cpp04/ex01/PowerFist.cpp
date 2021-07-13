#include "PowerFist.hpp"

PowerFist::PowerFist()
{
	this->name = "Power Fist";
	this->damage = 50;
	this->apcost = 8;
	std::cout << "PowerFist !!" << std::endl;
}

PowerFist::~PowerFist()
{
	std::cout << name << " is removed" << std::endl;
}

PowerFist::PowerFist(PowerFist const& origin)
{
	*this = origin;
}

PowerFist& PowerFist::operator=(PowerFist const& origin)
{
	this->name = origin.name;
	this->damage = origin.damage;
	this->apcost = origin.apcost;
}

void	PowerFist::attack() const
{
	std::cout << "* pschhh... SBAM! *" << std::endl;
}
