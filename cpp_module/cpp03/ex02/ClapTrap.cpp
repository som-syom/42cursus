#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	std::cout << "==== ClapTrap default is created ====" << std::endl;
	name = "none";
	hitpoints = 10;
	energe_points = 10;
	attack_damage = 0;
}

ClapTrap::ClapTrap(std::string n)
{
	std::cout << "==== ClapTrap " << n << " is created ====" << std::endl;
	name = n;
	hitpoints = 10;
	energe_points = 10;
	attack_damage = 0;
}

ClapTrap::~ClapTrap()
{
	std::cout << "==== ClapTrap " << this->name << " is removed ====" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const& origin)
{
	std::cout << "==== Copy constructor called ====" << std::endl;
	*this = origin;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& origin)
{
	std::cout << "==== Assignation operator called ====" << std::endl;
	name = origin.name;
	hitpoints = origin.hitpoints;
	energe_points = origin.hitpoints;
	attack_damage = origin.attack_damage;
	return (*this);
}

void ClapTrap::attack(std::string const& target)
{
	std::cout << "ClapTrap " << this->name << " attacks " << target;
	std::cout << ", causing " << this->attack_damage << " points of damage!";
	std::cout << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->name << " take attacks " << amount;
	std::cout << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap " << this->name << " be repaired " << amount;
	std::cout << std::endl;
}

std::string ClapTrap::getName(void)
{
	return (this->name);
}
