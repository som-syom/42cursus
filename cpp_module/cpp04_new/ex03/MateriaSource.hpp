#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include <string>

# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria *_learn[4];
	public:
		MateriaSource();
		~MateriaSource();
		MateriaSource(MateriaSource const&);
		MateriaSource& operator=(MateriaSource const&);

		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);

};

#endif
