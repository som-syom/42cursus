#include "PowerFist.hpp"

PowerFist::PowerFist() : AWeapon("Power Fist", 8, 50)
{
}

PowerFist::~PowerFist()
{
	std::cout << name << " is removed" << std::endl;
}

PowerFist::PowerFist(PowerFist const& origin) : AWeapon(origin)
{
}

PowerFist& PowerFist::operator=(PowerFist const& origin)
{
	this->name = origin.name;
	this->damage = origin.damage;
	this->apcost = origin.apcost;
	return (*this);
}

void	PowerFist::attack() const
{
	std::cout << "* pschhh... SBAM! *" << std::endl;
}
