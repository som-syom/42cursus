#ifndef TACTICALMARINE_HPP
# define TACTICALMARINE_HPP

# include <iostream>
# include <string>

# include "ISpaceMarine.hpp"

class TacticalMarine : public ISpaceMarine
{
	private:
		
	public:
		TacticalMarine();
		~TacticalMarine();
		TacticalMarine(TacticalMarine const&);
		TacticalMarine& operator=(TacticalMarine const&);

		ISpaceMarine* clone() const;
		void battleCry() const;
		void rangedAttack() const;
		void meleeAttack() const;
};

#endif
