#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
	protected:
		std::string		name;
		unsigned int	hitpoints;
		unsigned int	energe_points;
		unsigned int	attack_damage;
	public:
		ClapTrap();
		~ClapTrap();
		ClapTrap(std::string n);
		ClapTrap(ClapTrap const&);
		ClapTrap& operator=(ClapTrap const&);

		void attack(std::string const& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		std::string getName(void);
		unsigned int getHitpoints(void);
		unsigned int getEnergePoints(void);
		unsigned int getAttackDamage(void);
};

#endif