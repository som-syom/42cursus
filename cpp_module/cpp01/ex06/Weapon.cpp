#include "Weapon.hpp"

Weapon::Weapon()
{
	this->type = "nothing";
}

Weapon::Weapon(std::string type)
{
	this->type = type;
}

const std::string&	Weapon::getType()
{
	return (this->type);
}

void	Weapon::setType(const std::string type)
{
	this->type = type;
}