#ifndef RadScorpion_HPP
# define RadScorpion_HPP

# include <iostream>
# include <string>

# include "Enemy.hpp"

class RadScorpion : public Enemy
{
	private:
		
	public:
		RadScorpion();
		~RadScorpion();
		RadScorpion(RadScorpion const&);
		RadScorpion& operator=(RadScorpion const&);

		// virtual void takeDamage(int);

};

#endif
