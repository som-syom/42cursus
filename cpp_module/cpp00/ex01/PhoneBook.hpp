/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 06:29:03 by dhyeon            #+#    #+#             */
/*   Updated: 2021/06/21 00:28:42 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>

class PhoneBook {
	private:
		int			is_saved;
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
		int	isSaved(void);
		void setAllList(void);
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
		std::string getFirstName(void);
		std::string getLastName(void);
		std::string getNickame(void);
		std::string getLogin(void);
		std::string getPostalAddress(void);
		std::string getEmainAddress(void);
		std::string getPhoneNumber(void);
		std::string getBirthdatyDate(void);
		std::string getFavoriteMeal(void);
		std::string getUnderwearColor(void);
		std::string getDarkestSecret(void);
};

#endif
