#ifndef FIRE_HPP
# define FIRE_HPP

# include <iostream>
# include <string>

# include "AMateria.hpp"

class Fire : public AMateria
{
	private:
		
	public:
		Fire();
		~Fire();
		Fire(Fire const&);
		Fire& operator=(Fire const&);

		AMateria* clone() const;
		void use(ICharacter& target);

};

#endif
