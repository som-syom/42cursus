#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	std::cout << "==== DiamondTrap default is created ====" << std::endl;
	name = "none";
	hitpoints = 100;
	energe_points = 50;
	attack_damage = 30;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "==== DiamondTrap " << this->name << " is removed ====" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), FragTrap(name), ScavTrap(name)
{
	this->name = name;
}

DiamondTrap::DiamondTrap(DiamondTrap const& origin)
{
	std::cout << "==== Copy constructor called ====" << std::endl;
	*this = origin;
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap const& origin)
{
	std::cout << "==== Assignation operator called ====" << std::endl;
	this->name = origin.name;
	hitpoints = origin.hitpoints;
	energe_points = origin.hitpoints;
	attack_damage = origin.attack_damage;
	return (*this);
}


void DiamondTrap::attack(std::string const& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "         name is " << this->name << std::endl;
	std::cout << "clapTrap name is " << ClapTrap::name << std::endl;
}
