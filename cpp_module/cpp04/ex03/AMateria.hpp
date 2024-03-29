#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>

# include "ICharacter.hpp"
class ICharacter;

class AMateria
{
	protected:
		std::string		_type;
		unsigned int	_xp;
	public:
		AMateria();
		AMateria(std::string const& type);
		virtual ~AMateria();
		AMateria(AMateria const&);
		AMateria& operator=(AMateria const&);

		std::string const& getType() const;
		unsigned int getXP() const;

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);

};

#endif
