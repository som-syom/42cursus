#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap a("dhyeon");
	ScavTrap b;
	b = a;
	ScavTrap c("Cardet");
	ScavTrap d(c);

	d.attack(a.getName());
	b.takeDamage(20);
	a.beRepaired(5);
	a.guardGate();

	return (0);
}