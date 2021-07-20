#include "TacticalMarine.hpp"

TacticalMarine::TacticalMarine()
{
	std::cout << "Tactical Marine ready for battle!" << std::endl;
}

TacticalMarine::~TacticalMarine()
{
	std::cout << "Aaargh..." << std::endl;
}

TacticalMarine::TacticalMarine(TacticalMarine const& origin)
{
	*this = origin;
}

TacticalMarine& TacticalMarine::operator=(TacticalMarine const& origin)
{
	delete this;
	TacticalMarine *new_t = new TacticalMarine(origin);
	// this = new_t;
	return (*new_t);
}

ISpaceMarine* TacticalMarine::clone() const
{
	ISpaceMarine *t = new TacticalMarine(*this);
	return (t);//최근 개체를 복사하여 리턴
}

void TacticalMarine::battleCry() const
{
	std::cout << "For the holy PLOT!" << std::endl;
}

void TacticalMarine::rangedAttack() const
{
	std::cout << "* attacks with a bolter *" << std::endl;
}

void TacticalMarine::meleeAttack() const
{
	std::cout <<  "* attacks with a chainsword *" << std::endl;
}
