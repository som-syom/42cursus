#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	protected:
		std::string name;
	public:
		FragTrap();
		~FragTrap();
		FragTrap(std::string);
		FragTrap(FragTrap const&);
		FragTrap& operator=(FragTrap const&);

		void	highFiveGuys(void);
};

#endif