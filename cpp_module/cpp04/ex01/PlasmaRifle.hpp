#ifndef PLASMARIFLE_HPP
# define PLASMARIFLE_HPP

# include "AWeapon.hpp"

class PlasmaRifle : public AWeapon
{
	private:
		
	public:
		PlasmaRifle();
		~PlasmaRifle();
		PlasmaRifle(PlasmaRifle const&);
		PlasmaRifle& operator=(PlasmaRifle const&);

		void attack() const;
};

#endif
