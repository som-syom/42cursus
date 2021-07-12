#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "==== FragTrap default is created ====" << std::endl;
	name = "none";
	hitpoints = 100;
	energe_points = 100;
	attack_damage = 30;
}

FragTrap::~FragTrap()
{
	std::cout << "==== FragTrap " << this->name << " is removed ====" << std::endl;
}

FragTrap::FragTrap(std::string n) : ClapTrap(n)
{
	std::cout << "==== FragTrap " << n << " is created ====" << std::endl;
	this->name = n;
	hitpoints = 100;
	energe_points = 100;
	attack_damage = 30;
}

FragTrap::FragTrap(FragTrap const& origin) : ClapTrap(origin)
{
	std::cout << "==== Copy constructor called ====" << std::endl;
	*this = origin;
}

FragTrap& FragTrap::operator=(FragTrap const& origin)
{
	std::cout << "==== Assignation operator called ====" << std::endl;
	name = origin.name;
	hitpoints = origin.hitpoints;
	energe_points = origin.hitpoints;
	attack_damage = origin.attack_damage;
	return (*this);
}

void	FragTrap::highFiveGuys(void)
{
	std::cout << "!!! " << this->name << " gave a high five !!!" << std::endl; 
}
