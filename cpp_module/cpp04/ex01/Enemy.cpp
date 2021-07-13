#include "Enemy.hpp"

Enemy::Enemy(int hp, std::string const& type)
{
	this->type = type;
	this->hp = hp;
	std::cout << "Enemy" << this->type << " is created" << std::endl;
}

Enemy::~Enemy()
{
	std::cout << "Enemy" << this->type << " is removed" << std::endl;
}

Enemy::Enemy(Enemy const& origin)
{
	*this = origin;
}

Enemy& Enemy::operator=(Enemy const& origin)
{
	this->hp = origin.hp;
	this->type = origin.type;
}

void	takeDamage(int)
{

}
