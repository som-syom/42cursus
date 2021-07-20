#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_learn[i])
			delete this->_learn[i];
	}
}

MateriaSource::MateriaSource(MateriaSource const& origin)
{
	*this = origin;
}

MateriaSource& MateriaSource::operator=(MateriaSource const& origin)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_learn[i] != 0)
		{
			delete this->_learn[i];
			this->_learn[i] = 0;
		}
		this->_learn[i] = origin._learn[i];
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria* a)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_learn[i] && this->_learn[i]->getType().compare(a->getType()) == 0)
			break ;
		if (this->_learn[i] == 0)
		{
			this->_learn[i] = a;
			break ;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const& type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_learn[i] && type.compare(this->_learn[i]->getType()) == 0)
			return (this->_learn[i]->clone());
	}
	return (0);
}
