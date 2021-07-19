#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include <string>
# include "AWeapon.hpp"
# include "Enemy.hpp"

class Character
{
	private:
		std::string	name;
		int			AP;
		AWeapon		*weapon;
	public:
		Character(std::string const& name);
		Character();
		~Character();
		Character(Character const&);
		Character& operator=(Character const&);

		void recoverAP();
		void equip(AWeapon*);
		void attack(Enemy*);
		std::string getName() const;
		std::string getWeaponName() const;
		AWeapon* getWeapon() const;
		int getAP() const;

};

std::ostream& operator<<(std::ostream& out, const Character& c);

#endif
