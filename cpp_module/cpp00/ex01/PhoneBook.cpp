/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 06:28:17 by dhyeon            #+#    #+#             */
/*   Updated: 2021/06/21 02:24:35 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	PhoneBook::isSaved(void)
{
	if (this->is_saved == 1)
		return (1);
	else
		return (0);
}

void	PhoneBook::setAllList(void)
{
	std::string input;
	std::string list[11] = {"FIRST NAME",
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

	for (int i = 0; i < 11; i++)
	{
		if (i != 0 && input.empty())
			i--;
		std::cout << "Please input your " << list[i] << " : ";
		getline(std::cin, input);
		if (std::cin.eof())
			return ;
		if (i == 0)
			this->setFirstName(input);
		else if (i == 1)
			this->setLastName(input);
		else if (i == 2)
			this->setNickame(input);
		else if (i == 3)
			this->setLogin(input);
		else if (i == 4)
			this->setPostalAddress(input);
		else if (i == 5)
			this->setEmainAddress(input);
		else if (i == 6)
			this->setPhoneNumber(input);
		else if (i == 7)
			this->setBirthdatyDate(input);
		else if (i == 8)
			this->setFavoriteMeal(input);
		else if (i == 9)
			this->setUnderwearColor(input);
		else if (i == 10)
			this->setDarkestSecret(input);
	}
	this->is_saved = 1;
	std::cout << "---------- successfully saved ---------" << std::endl;
}

std::string	PhoneBook::getFirstName(void)
{
	return(this->first_name);
}

std::string	PhoneBook::getLastName(void)
{
	return (this->last_name);
}

std::string	PhoneBook::getNickame(void)
{
	return (this->nickname);
}
std::string	PhoneBook::getLogin(void)
{
	return (this->login);
}
std::string	PhoneBook::getPostalAddress(void)
{
	return (this->postal_address);
}
std::string	PhoneBook::getEmainAddress(void)
{
	return (this->email_address);
}
std::string	PhoneBook::getPhoneNumber(void)
{
	return (this->phone_number);
}
std::string	PhoneBook::getBirthdatyDate(void)
{
	return (this->birthday_date);
}
std::string	PhoneBook::getFavoriteMeal(void)
{
	return (this->favorite_meal);
}
std::string	PhoneBook::getUnderwearColor(void)
{
	return (this->underwear_color);
}
std::string	PhoneBook::getDarkestSecret(void)
{
	return (this->darkest_secret);
}

void	PhoneBook::setFirstName(const std::string str)
{
	this->first_name = str;
}

void	PhoneBook::setLastName(const std::string str)
{
	this->last_name = str;
}

void	PhoneBook::setNickame(const std::string str)
{
	this->nickname = str;
}
void	PhoneBook::setLogin(const std::string str)
{
	this->login = str;
}
void	PhoneBook::setPostalAddress(const std::string str)
{
	this->postal_address = str;
}
void	PhoneBook::setEmainAddress(const std::string str)
{
	this->email_address = str;
}
void	PhoneBook::setPhoneNumber(const std::string str)
{
	this->phone_number = str;
}
void	PhoneBook::setBirthdatyDate(const std::string str)
{
	this->birthday_date = str;
}
void	PhoneBook::setFavoriteMeal(const std::string str)
{
	this->favorite_meal = str;
}
void	PhoneBook::setUnderwearColor(const std::string str)
{
	this->underwear_color = str;
}
void	PhoneBook::setDarkestSecret(const std::string str)
{
	this->darkest_secret = str;
}