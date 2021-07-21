#ifndef WIND_HPP
# define WIND_HPP

# include <iostream>
# include <string>

# include "AMateria.hpp"

class Wind : public AMateria
{
	private:
		
	public:
		Wind();
		~Wind();
		Wind(Wind const&);
		Wind& operator=(Wind const&);

		AMateria* clone() const;
		void use(ICharacter& target);

};

#endif
