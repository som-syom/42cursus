#ifndef PINEAPPLEPIZZA_HPP
# define PINEAPPLEPIZZA_HPP

# include <iostream>
# include <string>

# include "Enemy.hpp"

class PineapplePizza : public Enemy
{
	private:
		
	public:
		PineapplePizza();
		~PineapplePizza();
		PineapplePizza(PineapplePizza const&);
		PineapplePizza& operator=(PineapplePizza const&);

};

#endif
