#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle()
{
	this->name = "Plasma Rifle";
	this->damage = 21;
	this->apcost = 5;
	std::cout << "Plasma Rifle !!!" << std::endl;
}

PlasmaRifle::~PlasmaRifle()
{
	std::cout << name << " is removed" << std::endl;
}

PlasmaRifle::PlasmaRifle(PlasmaRifle const& origin)
{
	*this = origin;
}

PlasmaRifle& PlasmaRifle::operator=(PlasmaRifle const& origin)
{
	this->name = origin.name;
	this->damage = origin.damage;
	this->apcost = origin.apcost;
	return (*this);
}

void	PlasmaRifle::attack() const
{
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}
