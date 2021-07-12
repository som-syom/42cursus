#include "DiamondTrap.hpp"

int main(void)
{
	std::cout << "-------------------------------------" << std::endl;
	DiamondTrap a("som");
	std::cout << "-------------------------------------" << std::endl;
	DiamondTrap aa;
	aa = a;
	std::cout << "-------------------------------------" << std::endl;
	DiamondTrap b("dhyeon");
	std::cout << "-------------------------------------" << std::endl;
	DiamondTrap bb(b);
	std::cout << "-------------------------------------" << std::endl;

	std::cout << b.getName() << "'s HP is " << b.getHitpoints() << std::endl;
	a.attack(b.getName());
	b.takeDamage(a.getAttackDamage());
	std::cout << b.getName() << "'s HP is " << b.getHitpoints() - a.getAttackDamage() << std::endl;
	b.beRepaired(5);
	std::cout << b.getName() << "'s HP is " << b.getHitpoints() - a.getAttackDamage() + 5 << std::endl;
	b.highFiveGuys();

	std::cout << "-------------------------------------" << std::endl;
		aa.attack(bb.getName());
	std::cout << "-------------------------------------" << std::endl;
	a.whoAmI();
	b.whoAmI();
	aa.whoAmI();
	bb.whoAmI();
	std::cout << "-------------------------------------" << std::endl;

	return (0);
}