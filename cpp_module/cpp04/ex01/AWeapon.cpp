#include "AWeapon.hpp"

AWeapon::AWeapon(std::string const& name, int apcost, int damage)
{
	this->name = name;
	this->apcost = apcost;
	this->damage = damage;
	std::cout << "a Weapon " << name << " is created" << std::endl;
}

AWeapon::~AWeapon()
{
	std::cout << "a Weapon " << name << " is removed" << std::endl;
}

AWeapon::AWeapon(AWeapon const& origin)
{
	*this = origin;
	std::cout << "a Weapon " << this->name << " Copy!!" << std::endl;
}

AWeapon& AWeapon::operator=(AWeapon const& origin)
{
	this->name = origin.name;
	this->apcost = origin.apcost;
	this->damage = origin.damage;
	std::cout << "a Weapon " << this->name << " == " << origin.name << std::endl;
	return (*this);
}

