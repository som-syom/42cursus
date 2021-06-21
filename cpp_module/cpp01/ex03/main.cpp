/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 19:02:09 by dhyeon            #+#    #+#             */
/*   Updated: 2021/06/21 20:07:07 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "ZombieHorde.hpp"

int	main(void)
{
	std::cout << "=== 2 Zombie Call ===" << std::endl;
	ZombieHorde *horde1 = new ZombieHorde(2);
	delete horde1;

	std::cout << "=== 4 Zombie Call ===" << std::endl;
	ZombieHorde horde2(4);

	return (0);
}