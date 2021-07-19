#include "PineapplePizza.hpp"

PineapplePizza::PineapplePizza() : Enemy(160, "PineapplePizza")
{
	std::cout << "HI IM PINEAPPLE PIZZZZZZA !!!" << std::endl;
}

PineapplePizza::~PineapplePizza()
{
	std::cout << "BYE BYE T_T" << std::endl;
}

PineapplePizza::PineapplePizza(PineapplePizza const& origin) : Enemy(origin)
{
}

PineapplePizza& PineapplePizza::operator=(PineapplePizza const& origin)
{
	this->hp = origin.hp;
	this->type = origin.type;
	return (*this);
}

