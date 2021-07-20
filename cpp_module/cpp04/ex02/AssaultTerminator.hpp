#ifndef ASSAULTTERMINATOR_HPP
# define ASSAULTTERMINATOR_HPP

# include <iostream>
# include <string>

# include "ISpaceMarine.hpp"

class AssaultTerminator : public ISpaceMarine
{
	private:
		
	public:
		AssaultTerminator();
		~AssaultTerminator();
		AssaultTerminator(AssaultTerminator const&);
		AssaultTerminator& operator=(AssaultTerminator const&);

		ISpaceMarine* clone() const;
		void battleCry() const;
		void rangedAttack() const;
		void meleeAttack() const;
};

#endif
