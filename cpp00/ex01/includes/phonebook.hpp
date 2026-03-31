/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odanyliu <odanyliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:53:06 by odanyliu          #+#    #+#             */
/*   Updated: 2026/02/23 17:54:11 by odanyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"

class PhoneBook
{
	private:
		Contact contactList[8];
		int		currentIndex;
		int		total;
		void	addContact(
			std::string firstName,
			std::string lastName,
			std::string nickName,
			std::string phoneNumber,
			std::string	darkestSecret
		);
		int		readSingleInput(std::string &str,std::string inputName);
		void	printSingleValue(std::string value);
		int		preciseSearch();
	public:
		PhoneBook();
		void read();
		void search();
};

#endif