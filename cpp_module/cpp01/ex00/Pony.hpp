/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 14:29:35 by dhyeon            #+#    #+#             */
/*   Updated: 2021/06/21 16:27:01 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONY_HPP
# define PONY_HPP

# include <iostream>
# include <string>

class Pony
{
	private:
		std::string	name;
		std::string	color;
		std::string favorite;
	public:
		void	setName(std::string);
		void	setColor(std::string);
		void	setFavorite(std::string);
		std::string	getName(void);
		std::string getColor(void);
		std::string getFavorite(void);
};

#endif