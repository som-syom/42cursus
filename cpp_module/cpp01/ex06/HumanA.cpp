#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : name(name), w(weapon)
{
	std::cout << "HumanA is created" << std::endl;
}

HumanA::~HumanA()
{
	std::cout << "HumanA is dead" << std::endl;
}

void	HumanA::setWeapon(Weapon &weapon)
{
	this->w = weapon;
}

void	HumanA::attack()
{
	std::cout << this->name << " attacks with his " << this->w.getType() << std::endl;
}