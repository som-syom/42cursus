#include "Character.hpp"

Character::Character()
{
	this->_name = "none";
	this->_inven[0] = 0;;
	this->_inven[1] = 0;;
	this->_inven[2] = 0;;
	this->_inven[3] = 0;;
}

Character::Character(std::string const& name)
{
	this->_name = name;
	this->_inven[0] = 0;;
	this->_inven[1] = 0;;
	this->_inven[2] = 0;;
	this->_inven[3] = 0;;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inven[i] != 0)
			delete this->_inven[i];
	}
}

Character::Character(Character const& origin)
{
	*this = origin;
}

Character& Character::operator=(Character const& origin)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inven[i] != 0)
		{
			delete this->_inven[i];
			this->_inven[i] = 0;
		}
		this->_inven[i] = origin._inven[i];
	}
	this->_name = origin._name;
	return (*this);
}

std::string const& Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inven[i] == 0)
		{
			this->_inven[i] = m;
			break ;
		}
	}
}

void Character::unequip(int idx)
{
	if (this->_inven[idx])
		this->_inven[idx] = 0;
}

void Character::use(int idx, ICharacter& target)
{
	if (this->_inven[idx])
		this->_inven[idx]->use(target);
}


