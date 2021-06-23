#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB
{
private:
	std::string	name;
	Weapon		*w;
public:
	HumanB(std::string);
	~HumanB();
	void	setWeapon(Weapon);
	void	attack();
};

#endif