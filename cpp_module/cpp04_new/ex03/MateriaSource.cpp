#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		this->_learn[i] = 0;
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
		// if (this->_learn[i] != 0)
		// {
		// 	delete this->_learn[i];
			this->_learn[i] = 0;
		// }
		if (origin._learn[i])
			this->_learn[i] = origin._learn[i]->clone();
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria* a)
{
	for (int i = 0; i < 4; i++)
	{
		std::cout << "i : " << i << std::endl;
		if (this->_learn[i] && this->_learn[i]->getType() == a->getType())
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
		if (this->_learn[i] && type == this->_learn[i]->getType())
			return (this->_learn[i]->clone());
	}
	return (0);
}
