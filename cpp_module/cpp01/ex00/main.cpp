/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 14:29:21 by dhyeon            #+#    #+#             */
/*   Updated: 2021/06/21 16:25:59 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

void	PonyOnTheStack(std::string name, std::string color, std::string favorite)
{
	Pony	p;

	p.setName(name);
	p.setColor(color);
	p.setFavorite(favorite);
	std::cout << "I'm " << p.getName() << "." << std::endl;
	std::cout << "My color is " << p.getColor() << "." << std::endl;
	std::cout << "I like " << p.getFavorite() << "." << std::endl;
}

void	PonyOnTheHeap(std::string name, std::string color, std::string favorite)
{
	Pony	*p = new Pony;

	p->setName(name);
	p->setColor(color);
	p->setFavorite(favorite);
	std::cout << "I'm " << p->getName() << "." << std::endl;
	std::cout << "My color is " << p->getColor() << "." << std::endl;
	std::cout << "I like " << p->getFavorite() << "." << std::endl;

	delete p;
}

int		main(void)
{
	std::cout << "==== PonyOnTheStack Call ====" << std::endl;
	PonyOnTheStack("Pinkie Pie", "Pink", "Cotton Candy");
	std::cout << "==== PonyOnTheStack End ====" << std::endl;
	
	std::cout << "==== PonyOnTheHeap Call ====" << std::endl;
	PonyOnTheHeap("Rarity", "Purple", "Dress");
	std::cout << "==== PonyOnTheHeap End ====" << std::endl;
	return (0);
}