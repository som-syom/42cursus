/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 17:54:16 by dhyeon            #+#    #+#             */
/*   Updated: 2021/06/16 18:04:51 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phone_book.hpp"

int		main(void)
{
	std::string	input;

	while (!std::cin.eof)
	{
		std::cin >> input;
		if (input.compare("ADD") == 0)
			std::cout << "ADD" << std::endl;
		else if (input.compare("SEARCH") == 0)
			std::cout << "SEARCH" << std::endl;
		else if (input.compare("EXIT") == 0)
			std::cout << "EXIT" << std::endl;
		else
			continue ;
	}
	return (0);
}