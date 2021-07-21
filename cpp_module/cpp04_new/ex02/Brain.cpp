#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "!! New Brain !!" << std::endl;
}

Brain::~Brain()
{
	std::cout << "!! Brain Bye !!" << std::endl;
}

Brain::Brain(Brain const& origin)
{
	*this = origin;
}

Brain& Brain::operator=(Brain const& origin)
{
	(void)origin;
	return (*this);
}

