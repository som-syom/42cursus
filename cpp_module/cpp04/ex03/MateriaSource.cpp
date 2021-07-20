#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	
}

MateriaSource::~MateriaSource()
{

}

MateriaSource::MateriaSource(MateriaSource const& origin)
{
	*this = origin;
}

MateriaSource& MateriaSource::operator=(MateriaSource const& origin)
{
	this->_learn = origin._learn;
	return (*this);
}

void MateriaSource::learnMateria(AMateria*)
{

}

AMateria* MateriaSource::createMateria(std::string const & type)
{

}
