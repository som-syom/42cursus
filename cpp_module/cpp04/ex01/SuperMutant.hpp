#ifndef SUPERMUTANT_HPP
# define SUPERMUTANT_HPP

# include <iostream>
# include <string>

# include "Enemy.hpp"

class SuperMutant : public Enemy
{
	private:
		
	public:
		SuperMutant();
		~SuperMutant();
		SuperMutant(SuperMutant const&);
		SuperMutant& operator=(SuperMutant const&);

		virtual void takeDamage(int);
};

#endif
