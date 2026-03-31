/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odanyliu <odanyliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:53:12 by odanyliu          #+#    #+#             */
/*   Updated: 2026/02/23 18:33:03 by odanyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact
{
private:
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkestSecret;
public:
	Contact();
	Contact(
		std::string firstName,
		std::string lastName,
		std::string nickName,
		std::string phoneNumber,
		std::string darkestSecret
	);
	void setFirstName(std::string value);
	void setLastName(std::string value);
	void setNickname(std::string value);
	void setPhoneNumber(std::string value);
	void setDarkestSecret(std::string value);

	std::string getFirstName(void);
	std::string getLastName(void);
	std::string getNickname(void);
	std::string getPhoneNumber(void);
	std::string getDarkestSecret(void);

	void    print();
};

#endif