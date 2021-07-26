#include "Character.hpp"

Character::Character()
{
	this->_name = "none";
	for (int i = 0; i < 4; i++)
		this->_inven[i] = 0;
	for (int i = 0; i < 10; i++)
		this->_temp[i] = 0;
}

Character::Character(std::string const& name)
{
	this->_name = name;
	for (int i = 0; i < 4; i++)
		this->_inven[i] = 0;
	for (int i = 0; i < 10; i++)
		this->_temp[i] = 0;
}

Character::~Character()
{
	for (int i = 0; i < 10; i++)
	{
		if (this->_temp[i] != 0)
			delete this->_temp[i];
	}
	std::cout << this->_name << " bye ~" << std::endl;
}

Character::Character(Character const& origin)
{
	for (int i = 0; i < 4; i++)
		this->_inven[i] = 0;
	for (int i = 0; i < 10; i++)
		this->_temp[i] = 0;
	*this = origin;
}

Character& Character::operator=(Character const& origin)
{
	for (int i = 0; i < 4; i++)
	{
		this->_inven[i] = 0;
		if (origin._inven[i])
			this->_inven[i] = origin._inven[i];
	}
	for (int i = 0; i < 10; i++)
	{
		if (origin._temp[i] != 0)
			this->_temp[i] = origin._temp[i]->clone();
		else
			this->_temp[i] = 0;
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
	if (m != 0)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->_inven[i] == 0)
			{
				this->_inven[i] = m;
				for (int i = 0; i < 10; i++)
				{
					if (this->_temp[i] == 0)
					{
						this->_temp[i] = m;
						break ;
					}
				}
				break ;
			}
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


