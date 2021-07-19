#ifndef FRYPAN_HPP
# define FRYPAN_HPP

# include <iostream>
# include <string>
# include "AWeapon.hpp"
class Frypan : public AWeapon
{
	private:
		
	public:
		Frypan();
		~Frypan();
		Frypan(Frypan const&);
		Frypan& operator=(Frypan const&);

		void	attack() const;
};

#endif
