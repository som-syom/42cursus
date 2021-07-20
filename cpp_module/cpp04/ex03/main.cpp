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

	std::cout << "----------------------[use test]" << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	std::cout << "----------------------[nonexist metaria test]" << std::endl;
	//nonexistent materia test
	me->unequip(3);
	me->use(3, *bob);
	std::cout << "----------------------[materiasource copy test]" << std::endl;
	MateriaSource* tst = new MateriaSource();
	tst->learnMateria(new Fire);
	MateriaSource* tst_dup = new MateriaSource(*tst);
	tst_dup->createMateria("fire");
	std::cout << "----------------------[character delete test]" << std::endl;
	delete bob;
	delete me;

	std::cout << "----------------------[materia source delete test]" << std::endl;
	delete tst_dup;
	delete src;

	return 0;
}