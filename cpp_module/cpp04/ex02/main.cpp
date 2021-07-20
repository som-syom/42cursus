#include "ISpaceMarine.hpp"
#include "ISquad.hpp"
#include "Squad.hpp"
#include "TacticalMarine.hpp"
#include "AssaultTerminator.hpp"

int main()
{
	ISpaceMarine* bob = new TacticalMarine;
	ISpaceMarine* jim = new AssaultTerminator;

	ISquad* vlc = new Squad;
	vlc->push(bob);
	vlc->push(jim);
	for (int i = 0; i < vlc->getCount(); ++i)
	{
		ISpaceMarine* cur = vlc->getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}
	delete vlc;

	std::cout << "---------------------------[new SpaceMarine]" << std::endl;

	ISpaceMarine* som1 = new TacticalMarine;
	ISpaceMarine* som2 = new AssaultTerminator;
	ISpaceMarine* som3 = new TacticalMarine;
	ISpaceMarine* som4 = new AssaultTerminator;
	ISpaceMarine* som5 = new TacticalMarine;
	ISpaceMarine* som6 = new AssaultTerminator;

	std::cout << "---------------------------[new Squad]" << std::endl;
	ISquad *cardet = new Squad;
	std::cout << "---------------------------[squad->push(space marine)]" << std::endl;
	std::cout << "count : " << cardet->push(som1) << std::endl;
	std::cout << "count : " << cardet->push(som2) << std::endl;
	std::cout << "count : " << cardet->push(som3) << std::endl;
	std::cout << "count : " << cardet->push(som4) << std::endl;
	std::cout << "count : " << cardet->push(som5) << std::endl;
	std::cout << "count : " << cardet->push(som6) << std::endl;
	std::cout << "---------------------------[unit test]" << std::endl;
	for (int i = 0; i < cardet->getCount(); i++)
	{
		ISpaceMarine* cur2 = cardet->getUnit(i);
		cur2->battleCry();
		cur2->rangedAttack();
		cur2->meleeAttack();
	}
	std::cout << "---------------------------[delete cardet squad]" << std::endl;
	delete cardet;

	std::cout << "---------------------------[assignment test]" << std::endl;
	ISquad *tst = new Squad;
	ISpaceMarine* dhyeon1 = new TacticalMarine;
	ISpaceMarine* dhyeon2 = new TacticalMarine;
	ISpaceMarine* dhyeon3 = new TacticalMarine;
	ISpaceMarine* dhyeon4 = new TacticalMarine;
	std::cout << "count : " << tst->push(dhyeon1) << std::endl;
	std::cout << "count : " << tst->push(dhyeon2) << std::endl;
	std::cout << "count : " << tst->push(dhyeon3) << std::endl;
	std::cout << "count : " << tst->push(dhyeon4) << std::endl;

	ISquad *tst2 = new Squad;
	ISpaceMarine* dhyeon5 = new AssaultTerminator;
	std::cout << "tst2 count : " << tst2->push(dhyeon5) << std::endl;
	tst2 = tst;
	std::cout << "assignment count : " << tst2->getCount() << std::endl;

	// std::cout << "---------------------------[copy test]" << std::endl;
	// Squad *tst3 = new Squad(*tst2);
	// std::cout << "copy count : " << tst3->getCount() << std::endl;



	std::cout << "---------------------------[delete]" << std::endl;
	// delete cardet;
	// delete tst;
	// delete tst2;
	// delete tst3;


	return 0;
}