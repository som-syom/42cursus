/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 06:28:17 by dhyeon            #+#    #+#             */
/*   Updated: 2021/06/16 22:08:00 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	PhoneBook::setFirstName(const std::string str)
{
	this->first_name = str;
}

void	PhoneBook::setLastName(const std::string str)
{
	this->last_name = str;
}

void PhoneBook::setNickame(const std::string str)
{
	this->nickname = str;
}
void PhoneBook::setLogin(const std::string str)
{
	this->login = str;
}
void PhoneBook::setPostalAddress(const std::string str)
{
	this->postal_address = str;
}
void PhoneBook::setEmainAddress(const std::string str)
{
	this->email_address = str;
}
void PhoneBook::setPhoneNumber(const std::string str)
{
	this->phone_number = str;
}
void PhoneBook::setBirthdatyDate(const std::string str)
{
	this->birthday_date = str;
}
void PhoneBook::setFavoriteMeal(const std::string str)
{
	this->favorite_meal = str;
}
void PhoneBook::setUnderwearColor(const std::string str)
{
	this->underwear_color = str;
}
void PhoneBook::setDarkestSecret(const std::string str)
{
	this->darkest_secret = str;
}