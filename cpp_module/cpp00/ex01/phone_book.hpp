/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone_book.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhyeon <dhyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 06:29:03 by dhyeon            #+#    #+#             */
/*   Updated: 2021/06/15 20:47:52 by dhyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

# include <iostream>
# include <string>

class phonebook {
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		int			login;
		std::string	postal_address;
		std::string	email_address;
		int			phone_number;
		std::string	birthday_date;
		std::string	favoritemeal;
		std::string	underwear_color;
		std::string	darkest_secret;
};

#endif
