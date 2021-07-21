#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include <string>

# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character : public ICharacter
{
	private:
		std::string	_name;
		AMateria*	_inven[4];
	public:
		Character();
		Character(std::string const&);
		~Character();
		Character(Character const&);
		Character& operator=(Character const&);

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);

};

#endif
