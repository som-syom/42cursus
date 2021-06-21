/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 14:29:30 by dhyeon            #+#    #+#             */
/*   Updated: 2021/06/21 16:18:20 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

void	Pony::setName(std::string name)
{
	this->name = name;
}

void	Pony::setColor(std::string color)
{
	this->color = color;
}

void	Pony::setFavorite(std::string favorite)
{
	this->favorite = favorite;
}

std::string	Pony::getName(void)
{
	return (this->name);
}

std::string	Pony::getColor(void)
{
	return (this->color);
}

std::string	Pony::getFavorite(void)
{
	return (this->favorite);
}
