#include "Victim.hpp"

Victim::Victim(std::string name)
{
	this->name = name;
	std::cout << "Some random victim called " << name << " just appeared!" << std::endl;
}

Victim::~Victim()
{
	std::cout << "Victim " << name << " just died for no apparent reason!" << std::endl;
}

Victim::Victim(Victim const& origin)
{
	std::cout << "Victim " << this->name << " Copy !!" << std::endl;
	*this = origin;
}

Victim& Victim::operator=(Victim const& origin)
{
	this->name = origin.name;
	std::cout << "Victim " << this->name << " == " << origin.name << std::endl;
	return (*this);
}

std::string Victim::getName()
{
	return (this->name);
}


void Victim::getPolymorphed() const
{
	std::cout << this->name << " has been turned into a cute little sheep!" << std::endl;
}

std::ostream& operator<<(std::ostream &out, Victim &v)
{
	out << "I am " << v.getName() << " and I like otters!" << std::endl;
	return (out);
}
