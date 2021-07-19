#include "Character.hpp"

Character::Character()
{
	this->name = "none";
	this->AP = 40;
	this->weapon = 0;
}

Character::Character(std::string const& name)
{
	this->name = name;
	this->AP = 40;
	this->weapon = 0;
}

Character::~Character()
{
	std::cout << "Character " << this->name << " is dead" << std::endl;
}

Character::Character(Character const& origin)
{
	*this = origin;
}

Character& Character::operator=(Character const& origin)
{
	this->name = origin.name;
	this->AP = origin.AP;
	this->weapon = origin.weapon;
	return (*this);
}

void Character::recoverAP()
{
	this->AP += 10;
	if (this->AP > 40)
		this->AP = 40;
}

void Character::equip(AWeapon* w)
{
	this->weapon = w;
}

void Character::attack(Enemy* e)
{
	if (this->AP - this->weapon->getAPCost() < 0)
		return ;
	std::cout << this->name << " attacks " << e->getType() << " with a " << this->weapon->getName() << std::endl;
	if (this->weapon != 0)
		this->weapon->attack();
	e->takeDamage(this->weapon->getDamage());
	if (e->getHP() <= 0)
		delete e;
	this->AP -= this->weapon->getAPCost();
}

std::string Character::getName() const
{
	return (this->name);
}

std::string Character::getWeaponName() const
{
	return (this->weapon->getName());
}

AWeapon *Character::getWeapon() const
{
	return (this->weapon);
}

int Character::getAP() const
{
	return (this->AP);
}

std::ostream& operator<<(std::ostream& out, const Character& c)
{
	if (c.getWeapon() == 0)
		out << c.getName() << " has " << c.getAP() << " AP and is unarmed" << std::endl;
	else
		out << c.getName() << " has " << c.getAP() << " AP and wields a " << c.getWeaponName() << std::endl;
	return (out);
}
