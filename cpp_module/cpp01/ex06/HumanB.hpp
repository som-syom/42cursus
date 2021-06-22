#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include <string>

class HumanB
{
private:
	std::string	name;
	std::string	weapon;
public:
	HumanB(std::string);
	~HumanB();
	void	setWeapon(Weapon);
	void	attack();
};


#endif