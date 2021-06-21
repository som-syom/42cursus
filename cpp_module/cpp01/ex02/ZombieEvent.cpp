/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 16:53:22 by dhyeon            #+#    #+#             */
/*   Updated: 2021/06/21 18:55:53 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent(void)
{
	this->type = "dead";
}

ZombieEvent::~ZombieEvent(void)
{
	std::cout << "ZombieEvent over" << std::endl;
}

void	ZombieEvent::setZombieType(std::string type)
{
	this->type = type;
}

Zombie	*ZombieEvent::newZombie(std::string name)
{
	return (new Zombie(name, this->type));
}

Zombie	*ZombieEvent::randomChump(void)
{
	std::string list[5] = {"dhyeon", "jachoi", "hyeyoo", "kankim", "hyulee"};
	srand(time(NULL));
	return (new Zombie(list[std::rand() % 5], this->type));
}