#include "Enemy.hpp"

Enemy::Enemy()
{
	this->type = "none";
	this->hp = 0;
}

Enemy::Enemy(int hp, std::string const& type)
{
	this->type = type;
	this->hp = hp;
}

Enemy::~Enemy()
{
}

Enemy::Enemy(Enemy const& origin)
{
	*this = origin;
}

Enemy& Enemy::operator=(Enemy const& origin)
{
	this->hp = origin.hp;
	this->type = origin.type;
	return (*this);
}

std::string Enemy::getType() const
{
	return (this->type);
}

int	Enemy::getHP() const
{
	return (this->hp);
}

void	Enemy::takeDamage(int damage)
{
	this->hp -= damage;
	if (this->hp < 0)
		this->hp = 0;
}
