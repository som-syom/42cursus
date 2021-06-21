/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 06:08:48 by dhyeon            #+#    #+#             */
/*   Updated: 2021/06/21 13:43:56 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int		main(int argc, char **argv)
{
	int	i;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; argv[i]; i++)
		{
			std::string str = argv[i];
			for (int j = 0; j < str.size(); j++)
				std::cout << char(toupper(str[j]));
		}
		std::cout << std::endl;
	}
	return (0);
}