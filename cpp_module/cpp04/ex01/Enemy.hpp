#ifndef ENEMY_HPP
# define ENEMY_HPP

# include <string>
# include <iostream>

class Enemy
{
	protected:
		std::string	type;
		int			hp;
		Enemy();
	public:
		Enemy(int hp, std::string const& type);
		virtual ~Enemy();
		Enemy(Enemy const&);
		Enemy& operator=(Enemy const&);

		std::string getType() const;
		int	getHP() const;

		virtual void takeDamage(int);
};

#endif
