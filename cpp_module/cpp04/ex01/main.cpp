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

	std::cout << "----------------------------[character born]" << std::endl;
	Character* som = new Character("som");
	std::cout << "----------------------------[std::cout << ]" << std::endl;
	std::cout << *som;

	std::cout << "----------------------------[Enemy born]" << std::endl;
	Enemy* pp = new PineapplePizza();
	std::cout << "----------------------------[weapon born]" << std::endl;
	AWeapon* fr = new Frypan();

	std::cout << "----------------------------[weapon equip]" << std::endl;
	som->equip(fr);
	std::cout << *som;
	std::cout << "----------------------------[attack pineapple]" << std::endl;
	std::cout << "pineapple HP : " << pp->getHP() << std::endl;
	som->attack(pp);
	std::cout << "pineapple HP : " << pp->getHP() << std::endl;
	std::cout << *som;
	som->attack(pp);
	std::cout << "pineapple HP : " << pp->getHP() << std::endl;
	std::cout << *som;

	std::cout << "----------------------------[ememy born]" << std::endl;
	Enemy* mutant = new SuperMutant();

	std::cout << "----------------------------[no ap test]" << std::endl;
	som->attack(mutant);

	std::cout << *som;
	std::cout << "----------------------------[recover ap]" << std::endl;
	som->recoverAP();
	std::cout << *som;
	std::cout << "----------------------------[attack]" << std::endl;
	som->attack(mutant);
	std::cout << *som;
	som->recoverAP();
	std::cout << *som;
	som->attack(mutant);
	std::cout << "mutant HP : " << mutant->getHP() << std::endl;
	std::cout << *som;

	std::cout << "----------------------------[delete character]" << std::endl;
	delete som; 
	std::cout << "----------------------------[delete weapon]" << std::endl;
	delete fr;
	
	return (0);
}
