/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 17:54:16 by dhyeon            #+#    #+#             */
/*   Updated: 2021/06/21 14:09:32 by dhyeon           ###   ########.fr       */
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
		std::cout << "=========== ADD PHONE BOOK ===========" << std::endl;
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
	
	for (int i = 0; i < 8; i++)
	{
		if (!list[i].isSaved())
			break ;
		std::string num;
		num += char(i + '0' + 1);
		std::cout << "|" << resizeString(num, 10) << "|";
		std::cout << resizeString(list[i].getFirstName(), 10) << "|";
		std::cout << resizeString(list[i].getLastName(), 10) << "|";
		std::cout << resizeString(list[i].getNickame(), 10) << "|" << std::endl;
		std::cout << line << std::endl;
	}
}

void	printAll(PhoneBook list)
{
	if (list.isSaved() == 0)
	{
		std::cout << "Error : INDEX IS EMPTY" << std::endl;
		return ;
	}
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
	std::cout << "--------------- [ ";
	std::cout << std::setw(10);
	std::cout << list.getNickame();
	std::cout << "'s INFO ] ---------------" << std::endl;
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
	std::cout << "-----------------------------------------------------" << std::endl;
}

void	commandSearch(PhoneBook *list)
{
	int			num;
	int			flag;

	std::cout << "============= SEARCH PHONE BOOK =============" << std::endl;
	printPreview(list);
	while (1)
	{
		flag = 0;
		num = 0;
		std::cout << "(if you want to go HOME, ENTER '0')" << std::endl;
		std::cout << "SELECT INDEX : ";
		std::cin >> std::noskipws >> num;
		if (std::cin.eof())
			return ;
		else if (std::cin.fail() || num >= 9)
		{
			std::cout << "Error : WRONG INPUT" << std::endl;
			flag = 1;
		}
		if (flag == 0)
		{
			if (num == 0)
			{
				std::cin.clear();
				fflush(stdin);
				return ;
			}
			else if (1 <= num && num <= 8)
				printAll(list[num - 1]);
			else
				std::cout << "Error : WRONG INPUT" << std::endl;
		}
		std::cin.clear();
		fflush(stdin);
	}

}

int		main(void)
{
	PhoneBook	list[8];
	std::string	input;

	std::cout << "========== [[ PHONE BOOK ]] ==========" << std::endl;
	std::cout << "*    Welcome Awesome My PhoneBook    *" << std::endl;
	std::cout << "*   [COMMAND : ADD, SEARCH, EXIT]    *" << std::endl;
	std::cout << "======================================" << std::endl;
	while (!std::cin.eof())
	{
		std::cout << "PLEASE ENTER COMMAND : ";
		getline(std::cin, input);
		if (std::cin.eof())
			return (0);
		if (input.compare("ADD") == 0)
			commandAdd(list);
		else if (input.compare("SEARCH") == 0)
			commandSearch(list);
		else if (input.compare("EXIT") == 0)
		{
			std::cout << "************* [ bye bye ] *************" << std::endl;
			return (0);
		}
		else
			std::cout << "[CHOOSE COMMAND : ADD, SEARCH, EXIT]" << std::endl;
	}
	return (0);
}