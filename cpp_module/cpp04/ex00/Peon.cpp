#include "Peon.hpp"

Peon::Peon(std::string name) : Victim(name)
{
	this->name = name;
	std::cout << "Zog zog." << std::endl;
}

Peon::~Peon()
{
	std::cout << "Bleuark..." << std::endl;
}

Peon::Peon(Peon const& origin)
{
	*this = origin;
}

Peon& Peon::operator=(Peon const& origin)
{
	this->name = origin.name;
	std::cout << "Peon " << this->name << " == " << origin.name << std::endl;
	return (*this);
}

void Peon::getPolymorphed() const
{
	std::cout << this->name << " has been turned into a pink pony!" << std::endl;
}
