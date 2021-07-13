#include "Som.hpp"

Som::Som(std::string name) : Victim(name)
{
	this->name = name;
	std::cout << "Hello Hi!" << std::endl;
}

Som::~Som()
{
	std::cout << "Bye Bye..." << std::endl;
}

Som::Som(Som const& origin)
{
	*this = origin;
}

Som& Som::operator=(Som const& origin)
{
	this->name = origin.name;
	std::cout << "Som " << this->name << " == " << origin.name << std::endl;
	return (*this);
}

void Som::getPolymorphed() const
{
	std::cout << this->name << " has been turned into a Cardet!" << std::endl;
}
