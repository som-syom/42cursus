#include "FragTrap.hpp"

int main(void)
{
	FragTrap a("dhyeon");
	FragTrap aa;
	aa = a;
	FragTrap b("jachoi");
	FragTrap bb(b);

	std::cout << b.getName() << "'s HP is " << b.getHitpoints() << std::endl;
	a.attack(b.getName());
	b.takeDamage(a.getAttackDamage());
	std::cout << b.getName() << "'s HP is " << b.getHitpoints() - a.getAttackDamage() << std::endl;
	b.beRepaired(5);
	std::cout << b.getName() << "'s HP is " << b.getHitpoints() - a.getAttackDamage() + 5 << std::endl;
	a.highFiveGuys();

	return (0);
}