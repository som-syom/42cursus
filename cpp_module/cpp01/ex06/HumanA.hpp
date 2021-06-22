#ifndef HUMANA_HPP
# define HUMANA_HPP

class HumanA
{
private:
	std::string	name;
	Weapon		w;
public:
	HumanA(std::string, Weapon);
	~HumanA();
	void	setWeapon(Weapon);
	void	attack();
};

#endif