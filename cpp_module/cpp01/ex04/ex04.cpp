/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 20:09:55 by dhyeon            #+#    #+#             */
/*   Updated: 2021/06/21 20:32:27 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void)
{
	std::string str= "HI THIS IS BRAIN";
	std::string *pointer = &str;
	std::string &reference = str;

	std::cout << "=== original ====" << std::endl;
	std::cout << str << std::endl;
	std::cout << "=== reference ===" << std::endl;
	std::cout << reference << std::endl;
	std::cout << "==== pointer ====" << std::endl;
	std::cout << *pointer << std::endl;
	return (0);
}