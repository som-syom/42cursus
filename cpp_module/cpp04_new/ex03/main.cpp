#include "IMateriaSource.hpp"
#include "ICharacter.hpp"
#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Fire.hpp"
#include "Wind.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Fire());
	src->learnMateria(new Wind());

	ICharacter* me = new Character("me");

	std::cout << "----------------------[mandatory test]" << std::endl;
	AMateria* tmp;
	tmp = src->createMateria("ice");
	std::cout << "tmp return : " << tmp << std::endl;
	me->equip(tmp);
	tmp = src->createMateria("cure");
	std::cout << "tmp return : " << tmp << std::endl;
	me->equip(tmp);
	tmp = src->createMateria("fire");
	std::cout << "tmp return : " << tmp << std::endl;
	me->equip(tmp);
	tmp = src->createMateria("wind");
	std::cout << "tmp return : " << tmp << std::endl;
	me->equip(tmp);
	std::cout << "----------------------[unknown type test]" << std::endl;
	tmp = src->createMateria("lighting");
	std::cout << "unknown type case : " << tmp << std::endl;
	me->equip(tmp);
	std::cout << "----------------------[unequip test]" << std::endl;
	for (int i = 0; i < 4; i++)
		me->unequip(i);

	std::cout << "----------------------[new character]" << std::endl;
	ICharacter* bob = new Character("bob");

	std::cout << "----------------------[0equip use test]" << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);

	std::cout << "----------------------[nonexist metaria test]" << std::endl;
	me->unequip(3);
	me->use(3, *bob);

	std::cout << "----------------------[materiasource assignment test]" << std::endl;
	MateriaSource* som1 = new MateriaSource();
	som1->learnMateria(new Fire);

	MateriaSource* som2 = new MateriaSource();
	som2->learnMateria(new Ice);
	som2->learnMateria(new Wind);
	som2->learnMateria(new Cure);

	Character* dhyeon = new Character("dhyeon");

	dhyeon->equip(som1->createMateria("fire"));
	dhyeon->equip(som1->createMateria("ice")); // <- fail
	dhyeon->use(0, *bob);
	dhyeon->use(1, *bob); // <- fail

	std::cout << "aaa " << std::endl;
	*som1 = *som2;
	dhyeon->equip(som1->createMateria("fire"));
	dhyeon->equip(som1->createMateria("ice"));
	dhyeon->use(0, *bob);
	dhyeon->use(1, *bob);


	std::cout << "----------------------[materiasource copy test]" << std::endl;
	MateriaSource* tst = new MateriaSource();
	tst->learnMateria(new Fire);
	MateriaSource tst_dup(*tst);
	Character dup;
	dup.equip(tst_dup.createMateria("fire"));
	dup.use(0, *bob);

	std::cout << "----------------------[character copy test]" << std::endl;
	Character dhyeon1(*dhyeon);
	dhyeon1.use(0, *bob);

	std::cout << "----------------------[character assignment test]" << std::endl;
	Character* dhyeon2 = new Character;
	som1->learnMateria(new Wind);
	dhyeon2->equip(som1->createMateria("wind"));
	dhyeon2->use(0, *bob);
	*dhyeon2 = *dhyeon;
	dhyeon2->use(0, *bob);

	std::cout << "----------------------[materia xp test]" << std::endl;
	AMateria* c = new Cure;
	dhyeon2->equip(c);
	std::cout << "cure xp = " << c->getXP() << std::endl;
	dhyeon2->use(2, *bob);
	std::cout << "cure xp = " << c->getXP() << std::endl;
	dhyeon2->use(2, *bob);
	std::cout << "cure xp = " << c->getXP() << std::endl;

	std::cout << "----------------------[character delete test]" << std::endl;
	delete bob;
	delete me;
	delete dhyeon2;
	delete dhyeon;

	std::cout << "----------------------[materia source delete test]" << std::endl;
	delete tst;
	delete src;
	delete som1;
	delete som2;

	std::cout << "----------------------[end]" << std::endl;

	// while (1) ;
	return 0;
}