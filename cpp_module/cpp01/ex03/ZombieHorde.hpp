/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 19:03:08 by dhyeon            #+#    #+#             */
/*   Updated: 2021/06/21 19:49:17 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP

# include <iostream>
# include <cstdlib>
# include <ctime>
# include "Zombie.hpp"

class ZombieHorde
{
	private:
		int		num;
		Zombie	*zombie;
	public:
		ZombieHorde(int n);
		~ZombieHorde(void);
		std::string	randChumpName(void);
};

#endif