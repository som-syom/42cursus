#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->w = 0;
	std::cout << "HumanB is created" << std::endl;
}

HumanB::~HumanB()
{
	std::cout << "HumanB is dead" << std::endl;
}

void	HumanB::setWeapon(Weapon weapon)
{
	this->w = &weapon;
}

void	HumanB::attack()
{
	std::cout << this->name << " attacks with his " << this->w->getType() << std::endl;
}
