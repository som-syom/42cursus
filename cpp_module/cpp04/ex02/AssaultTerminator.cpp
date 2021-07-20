#include "AssaultTerminator.hpp"

AssaultTerminator::AssaultTerminator()
{
	std::cout <<  "* teleports from space *" << std::endl;
}

AssaultTerminator::~AssaultTerminator()
{
	std::cout << "I’ll be back..." << std::endl;
}

AssaultTerminator::AssaultTerminator(AssaultTerminator const& origin)
{
	*this = origin;
}

AssaultTerminator& AssaultTerminator::operator=(AssaultTerminator const& origin)
{
	delete this;
	AssaultTerminator *new_t = new AssaultTerminator(origin);
	return (*new_t);
}

ISpaceMarine* AssaultTerminator::clone() const
{
	ISpaceMarine *t = new AssaultTerminator(*this);
	return (t);
}

void AssaultTerminator::battleCry() const
{
	std::cout << "This code is unclean. PURIFY IT!" << std::endl;
}

void AssaultTerminator::rangedAttack() const
{
	std::cout << "* does nothing *" << std::endl;
}

void AssaultTerminator::meleeAttack() const
{
	std::cout <<  "* attacks with chainfists *" << std::endl;
}
