/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 06:29:03 by dhyeon            #+#    #+#             */
/*   Updated: 2021/06/16 19:50:27 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>

class PhoneBook {
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	login;
		std::string	postal_address;
		std::string	email_address;
		std::string	phone_number;
		std::string	birthday_date;
		std::string	favorite_meal;
		std::string	underwear_color;
		std::string	darkest_secret;
	public:
		void setFirstName(const std::string);
		void setLastName(const std::string);
		void setNickame(const std::string);
		void setLogin(const std::string);
		void setPostalAddress(const std::string);
		void setEmainAddress(const std::string);
		void setPhoneNumber(const std::string);
		void setBirthdatyDate(const std::string);
		void setFavoriteMeal(const std::string);
		void setUnderwearColor(const std::string);
		void setDarkestSecret(const std::string);
};

#endif
