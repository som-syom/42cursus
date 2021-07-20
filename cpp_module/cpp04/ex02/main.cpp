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

	std::cout << "---------------------------" << std::endl;

	ISpaceMarine* som1 = new TacticalMarine;
	ISpaceMarine* som2 = new AssaultTerminator;
	ISpaceMarine* som3 = new TacticalMarine;
	ISpaceMarine* som4 = new AssaultTerminator;
	ISpaceMarine* som5 = new TacticalMarine;
	ISpaceMarine* som6 = new AssaultTerminator;

	ISquad *cardet = new Squad;
	std::cout << "count : " << cardet->push(som1) << std::endl;
	std::cout << "count : " << cardet->push(som2) << std::endl;
	std::cout << "count : " << cardet->push(som3) << std::endl;
	std::cout << "count : " << cardet->push(som4) << std::endl;
	std::cout << "count : " << cardet->push(som5) << std::endl;
	std::cout << "count : " << cardet->push(som6) << std::endl;
	for (int i = 0; i < cardet->getCount(); ++i)
	{
		ISpaceMarine* cur2 = cardet->getUnit(i);
		cur2->battleCry();
		cur2->rangedAttack();
		cur2->meleeAttack();
	}
	delete cardet;


	return 0;
}