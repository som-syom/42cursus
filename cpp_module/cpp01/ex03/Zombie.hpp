/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 16:53:19 by dhyeon            #+#    #+#             */
/*   Updated: 2021/06/21 19:44:20 by dhyeon           ###   ########.fr       */
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
		Zombie();
		Zombie(std::string name, std::string type);
		~Zombie();
		void	announce(void);
		void	setName(std::string);
		void	setType(std::string);
};

#endif