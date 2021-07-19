#include "AWeapon.hpp"

AWeapon::AWeapon(std::string const& name, int apcost, int damage)
{
	this->name = name;
	this->apcost = apcost;
	this->damage = damage;
}

AWeapon::~AWeapon()
{
}

AWeapon::AWeapon(AWeapon const& origin)
{
	*this = origin;
}

AWeapon& AWeapon::operator=(AWeapon const& origin)
{
	this->name = origin.name;
	this->apcost = origin.apcost;
	this->damage = origin.damage;
	return (*this);
}

std::string AWeapon::getName() const
{
	return (this->name);
}

int AWeapon::getAPCost() const
{
	return (this->apcost);
}

int AWeapon::getDamage() const
{
	return (this->damage);
}

