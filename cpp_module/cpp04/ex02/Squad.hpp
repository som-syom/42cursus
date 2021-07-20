#ifndef SQUAD_HPP
# define SQUAD_HPP

# include <iostream>
# include <string>
# include "ISquad.hpp"

class Squad : public ISquad
{
	private:
		int	count;
		ISpaceMarine** unit;
	public:
		Squad();
		~Squad();
		Squad(Squad const&);
		Squad& operator=(Squad const&);

		int getCount() const;
		ISpaceMarine* getUnit(int) const;
		int push(ISpaceMarine*);

};

#endif
