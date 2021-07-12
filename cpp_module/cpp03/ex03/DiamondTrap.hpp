#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"
# include "ClapTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap, public ClapTrap
{
	private:

	public:
		DiamondTrap();
		~DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(DiamondTrap const&);
		DiamondTrap& operator=(DiamondTrap const&);

		void attack(std::string const& target);
		void whoAmI();
};

#endif
