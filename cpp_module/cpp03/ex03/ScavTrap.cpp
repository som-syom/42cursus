#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "==== ScavTrap default is created ====" << std::endl;
	name = "none";
	hitpoints = 100;
	energe_points = 50;
	attack_damage = 20;
}

ScavTrap::~ScavTrap()
{
	std::cout << "==== ScavTrap " << this->name << " is removed ====" << std::endl;
}

ScavTrap::ScavTrap(std::string n) : ClapTrap(n)
{
	std::cout << "==== ScavTrap " << n << " is created ====" << std::endl;
	this->name = n;
	hitpoints = 100;
	energe_points = 50;
	attack_damage = 20;
}

ScavTrap::ScavTrap(ScavTrap const& origin)
{
	std::cout << "==== Copy constructor called ====" << std::endl;
	*this = origin;
}

ScavTrap& ScavTrap::operator=(ScavTrap const& origin)
{
	std::cout << "==== Assignation operator called ====" << std::endl;
	name = origin.name;
	hitpoints = origin.hitpoints;
	energe_points = origin.hitpoints;
	attack_damage = origin.attack_damage;
	return (*this);
}


void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->name << " have enterred in Gate keeper mode !!" << std::endl;
}
