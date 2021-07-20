#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include <string>

# include "AMateria.hpp"

class Cure : public AMateria
{
	private:
		
	public:
		Cure();
		~Cure();
		Cure(Cure const&);
		Cure& operator=(Cure const&);

		AMateria* clone() const;
		void use(ICharacter& target);

};

#endif
