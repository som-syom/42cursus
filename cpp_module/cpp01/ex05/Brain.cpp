#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain is created" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain is removed" << std::endl;
}

const Brain* Brain::identify() const
{
	return (this);
}