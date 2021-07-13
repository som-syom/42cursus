#include "Enemy.hpp"

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

}

Enemy& Enemy::operator=(Enemy const& origin)
{

}

void	takeDamage(int)
{

}
