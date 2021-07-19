#include "Frypan.hpp"

Frypan::Frypan() : AWeapon("Frypan", 15, 100)
{
}

Frypan::~Frypan()
{
}

Frypan::Frypan(Frypan const& origin) : AWeapon(origin)
{
}

Frypan& Frypan::operator=(Frypan const& origin)
{
	this->name = origin.name;
	this->apcost = origin.apcost;
	this->damage = origin.damage;
	return (*this);
}

void	Frypan::attack() const
{
	std::cout << "kkweeeeeng!!! Taaang!!" << std::endl;
}
