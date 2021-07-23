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
	for (int i = 0; i < 100; i++)
	{
		// std::cout << "i : " << i << std::endl;
		this->_idea[i] = origin._idea[i];
	}
	return (*this);
}

void Brain::setIdea(int idx, std::string const& idea)
{
	this->_idea[idx] = idea;
}

std::string Brain::getIdea(int idx)
{
	return (this->_idea[idx]);
}

