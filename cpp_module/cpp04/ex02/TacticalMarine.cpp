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
	(void)origin;
	return (*this);
}

ISpaceMarine* TacticalMarine::clone() const
{
	ISpaceMarine *t = new TacticalMarine(*this);
	return (t);
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
