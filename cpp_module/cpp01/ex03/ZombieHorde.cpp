/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 19:25:15 by dhyeon            #+#    #+#             */
/*   Updated: 2021/07/01 16:10:48 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"
#include "Zombie.hpp"

std::string	ZombieHorde::randChumpName(void)
{
	std::string	list[5] = {"dhyeon", "jachoi", "kankim", "llim", "hyulee"};
	return (list[std::rand() % 5]);
}

ZombieHorde::ZombieHorde(int n)
{
	this->num = n;
	this->zombie = new Zombie[n];
	srand(time(NULL));

	for (int i = 0; i < n; i++)
	{
		this->zombie[i].setName(randChumpName());
		this->zombie[i].setType("ZZangZombie");
		this->zombie[i].announce();
	}
}

ZombieHorde::~ZombieHorde()
{
	delete [] zombie;
	std::cout << this->num << " zombies were died" << std::endl;
}
