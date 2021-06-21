/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 16:53:19 by dhyeon            #+#    #+#             */
/*   Updated: 2021/06/21 18:39:04 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>
# include <cstdlib>
# include <ctime>

class Zombie
{
	private:
		std::string	name;
		std::string	type;
	public:
		Zombie(std::string name, std::string type);
		~Zombie();
		void	announce(void);
};

#endif