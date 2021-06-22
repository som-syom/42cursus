#include "Human.hpp"
#include "Brain.hpp"

Human::Human()
{
	std::cout << "Human is created" << std::endl;
}

Human::~Human()
{
	std::cout << "Human died" << std::endl;
}

const Brain*	Human::identify() const
{
	return (this->b.identify());
}

const Brain&	Human::getBrain() const
{
	return (this->b);
}