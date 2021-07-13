#ifndef POWERFIST_HPP
# define POWERFIST_HPP

# include "AWeapon.hpp"

class PowerFist : public AWeapon
{
	private:
		
	public:
		PowerFist();
		~PowerFist();
		PowerFist(PowerFist const&);
		PowerFist& operator=(PowerFist const&);

		void	attack() const;
};

#endif
