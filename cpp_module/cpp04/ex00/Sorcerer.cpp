#include "Sorcerer.hpp"

Sorcerer::Sorcerer(std::string name, std::string title)
{
	this->name = name;
	this->title = title;
	std::cout << name << ", " << title << ", is born!" << std::endl;
}

Sorcerer::~Sorcerer()
{
	std::cout << name << ", " << title << ", is dead. Consequences will never be the same!" << std::endl;
}

Sorcerer::Sorcerer(Sorcerer const& origin)
{
	std::cout << "Sorcerer " << this->name << " Copy !!" << std::endl;
	*this = origin;
}

Sorcerer& Sorcerer::operator=(Sorcerer const& origin)
{
	this->name = origin.name;
	this->title = origin.title;
	std::cout << "Sorcerer " << this->name << " == " << origin.name << std::endl;
	return (*this);
}

std::string Sorcerer::getName()
{
	return (this->name);
}

std::string Sorcerer::getTitle()
{
	return (this->title);
}

void Sorcerer::polymorph(Victim const& v) const
{
	v.getPolymorphed();
}

std::ostream& operator<<(std::ostream &out, Sorcerer &s)
{
	out << "I am " << s.getName() << ", " << s.getTitle() << ", and I like ponies!" << std::endl;
	return (out);
}
