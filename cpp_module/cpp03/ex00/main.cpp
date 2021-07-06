#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap one("dasom");
	ClapTrap two("som");

	ClapTrap three;
	three = one;
	ClapTrap four(two);

	one.attack(two.getName());
	two.takeDamage(0);
	one.beRepaired(5);

	return (0);
}