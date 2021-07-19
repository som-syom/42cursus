#include "SuperMutant.hpp"

SuperMutant::SuperMutant()
{
	this->type = "Super Mutant";
	this->hp = 170;
	std::cout <<  "Gaaah. Me want smash heads!" << std::endl;
}

SuperMutant::~SuperMutant()
{
	std::cout << "Aaargh..." << std::endl;
}

SuperMutant::SuperMutant(SuperMutant const& origin)
{
	*this = origin;
}

SuperMutant& SuperMutant::operator=(SuperMutant const& origin)
{
	this->type = origin.type;
	this->hp = origin.hp;
	return (*this);
}

void SuperMutant::takeDamage(int damage)
{
	this->hp -= (damage - 3);
	if (this->hp < 0)
		this->hp = 0;
}
