/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 16:53:07 by dhyeon            #+#    #+#             */
/*   Updated: 2021/06/21 18:56:10 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "ZombieEvent.hpp"

int	main(void)
{
	ZombieEvent	zombie_event;
	Zombie		*z1 = zombie_event.newZombie("som");
	z1->announce();
	delete z1;

	zombie_event.setZombieType("zzang");
	Zombie		*z2 = new Zombie("dasom", "ZZzangzzang");
	z2->announce();
	delete z2;

	Zombie		*z3 = zombie_event.randomChump();
	z3->announce();
	delete z3;
	return (0);
}