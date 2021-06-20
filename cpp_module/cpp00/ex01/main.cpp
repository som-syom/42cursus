/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 17:54:16 by dhyeon            #+#    #+#             */
/*   Updated: 2021/06/21 02:41:23 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	commandAdd(PhoneBook *list)
{
	std::string	input;
	int			i;

	for (i = 0; i < 8; i++)
	{
		if (list[i].isSaved() == 0)
			break ;
	}
	if (i == 8)
	{
		std::cout << "PhoneBook is FULL" << std::endl;
		return ;
	}
	else
	{
		std::cout << "========== ADD PHONE BOOK ==========" << std::endl;
		list[i].setAllList();
	}
}

std::string	resizeString(std::string str, int len)
{
	int	str_len = str.length();

	if (str_len == len)
		return (str);
	else if (str_len < len)
	{
		str.insert(str.begin(), (len - str_len), ' ');
		return (str);
	}
	else
	{
		str.resize(len - 1);
		str += '.';
		return (str);
	}
}

void	printPreview(PhoneBook *list)
{
	std::string line;

	line.insert(line.begin(), 45, '-');
	std::cout << line << std::endl;
	std::cout << "|" << resizeString("INDEX", 10) << "|";
	std::cout << resizeString("FIRSTNAME", 10) << "|";
	std::cout << resizeString("LASTNAME", 10) << "|";
	std::cout << resizeString("NICKNAME", 10) << "|" << std::endl;
	std::cout << line << std::endl;
	
	for (int i = 0; i < 4; i++)
	{
		if (!list[i].isSaved())
			break ;
		std::string num = std::to_string(i + 1);
		std::cout << "|" << resizeString(num, 10) << "|";
		std::cout << resizeString(list[i].getFirstName(), 10) << "|";
		std::cout << resizeString(list[i].getLastName(), 10) << "|";
		std::cout << resizeString(list[i].getNickame(), 10) << "|" << std::endl;
		std::cout << line << std::endl;
	}
}

void	printAll(PhoneBook list)
{
	std::string set[11] = {"FIRST NAME",
						"LAST NAME",
						"NICKNAME",
						"LOGIN",
						"POSTAL ADDRESS",
						"EMAIL ADDRESS",
						"PHONE NUMBER",
						"BIRTHDAY DATE",
						"FAVORITE MEAL",
						"UNDERWEAR COLOR",
						"DARKEST SECRET"};
	std::cout << "--------------- [ " << list.getNickame() << "'s INFO ] ---------------" << std::endl;
	std::cout << resizeString(set[0], 16) << " : " << list.getFirstName() << std::endl;
	std::cout << resizeString(set[1], 16) << " : " << list.getLastName() << std::endl;
	std::cout << resizeString(set[2], 16) << " : " << list.getNickame() << std::endl;
	std::cout << resizeString(set[3], 16) << " : " << list.getLogin() << std::endl;
	std::cout << resizeString(set[4], 16) << " : " << list.getPostalAddress() << std::endl;
	std::cout << resizeString(set[5], 16) << " : " << list.getEmainAddress() << std::endl;
	std::cout << resizeString(set[6], 16) << " : " << list.getPhoneNumber() << std::endl;
	std::cout << resizeString(set[7], 16) << " : " << list.getBirthdatyDate() << std::endl;
	std::cout << resizeString(set[8], 16) << " : " << list.getFavoriteMeal() << std::endl;
	std::cout << resizeString(set[9], 16) << " : " << list.getUnderwearColor() << std::endl;
	std::cout << resizeString(set[10], 16) << " : " << list.getDarkestSecret() << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;
}

void	commandSearch(PhoneBook *list)
{
	std::string input;
	int			num;
	int			flag;

	std::cout << "========== SEARCH PHONE BOOK ==========" << std::endl;
	printPreview(list);
	while (1)
	{
		flag = 0;
		std::cout << "(if you want to go HOME, ENTER '0')" << std::endl;
		std::cout << "SELECT INDEX : ";
		getline(std::cin, input);
		if (std::cin.eof())
			return ;
		for (int i = 0; i < input.size(); i++)
			if (!('0' <= input[i] && input[i] <= '8'))
			{
				std::cout << "WRONG INPUT" << std::endl;
				flag = 1;
				break ;
			}
		if (flag == 0)
		{
			num = stoi(input);
			if (num == 0)
				return ;
			else if (1 <= num && num <= 8)
			{
				printAll(list[num - 1]);
			}
		}
	}

}

int		main(void)
{
	PhoneBook	list[8];
	std::string	input;

	std::cout << "========== [[ PHONE BOOK ]] ==========" << std::endl;
	while (!std::cin.eof())
	{
		std::cout << "PLEASE ENTER COMMAND : ";
		getline(std::cin, input);
		if (std::cin.eof())
			return (0);
		if (input.compare("ADD") == 0)
		{
			std::cout << "ADD" << std::endl;
			commandAdd(list);
		}
		else if (input.compare("SEARCH") == 0)
		{
			std::cout << "SEARCH" << std::endl;
			commandSearch(list);
		}
		else if (input.compare("EXIT") == 0)
			std::cout << "EXIT" << std::endl;
		else
			continue ;
	}
	return (0);
}