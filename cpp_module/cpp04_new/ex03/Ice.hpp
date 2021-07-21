#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include <string>

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Ice : public AMateria
{
	private:
		
	public:
		Ice();
		~Ice();
		Ice(Ice const&);
		Ice& operator=(Ice const&);

		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif
