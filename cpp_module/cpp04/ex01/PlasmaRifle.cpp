#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle() : AWeapon("Plasma Rifle", 5, 21)
{
}

PlasmaRifle::~PlasmaRifle()
{
}

PlasmaRifle::PlasmaRifle(PlasmaRifle const& origin) : AWeapon(origin)
{
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
