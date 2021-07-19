#include "AWeapon.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "Enemy.hpp"
#include "SuperMutant.hpp"
#include "RadScorpion.hpp"
#include "Character.hpp"
#include "PineapplePizza.hpp"
#include "Frypan.hpp"

int main(void)
{
	Character* me = new Character("me");

	std::cout << *me;

	Enemy* b = new RadScorpion();

	AWeapon* pr = new PlasmaRifle();
	AWeapon* pf = new PowerFist();

	me->equip(pr);
	std::cout << *me;
	me->equip(pf);

	me->attack(b);
	std::cout << *me;
	me->equip(pr);
	std::cout << *me;
	me->attack(b);
	std::cout << *me;
	me->attack(b);
	std::cout << *me;

	delete pr;
	delete pf;
	delete me;

	std::cout << "----------------------------" << std::endl;

	Character* som = new Character("som");
	std::cout << *som;

	Enemy* pp = new PineapplePizza();
	AWeapon* fr = new Frypan();

	som->equip(fr);
	std::cout << *som;
	som->attack(pp);
	std::cout << *som;
	som->attack(pp);
	std::cout << *som;

	Enemy* mutant = new SuperMutant();

	som->attack(mutant);
	//no ap
	std::cout << *som;
	som->recoverAP();
	std::cout << *som;
	som->attack(mutant);
	std::cout << *som;
	som->recoverAP();
	std::cout << *som;
	som->attack(mutant);
	std::cout << *som;

	delete som; 
	delete fr;
	
	return (0);
}
