/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odanyliu <odanyliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:52:58 by odanyliu          #+#    #+#             */
/*   Updated: 2026/02/23 18:35:17 by odanyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/contact.hpp"

Contact::Contact(){}

Contact::Contact(
	std::string firstName,
	std::string lastName,
	std::string nickName,
	std::string phoneNumber,
	std::string darkestSecret
)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->nickName = nickName;
	this->phoneNumber = phoneNumber;
	this->darkestSecret = darkestSecret;
}

void	Contact::setFirstName(std::string value) {
	firstName = value;
}

void	Contact::setLastName(std::string value) {
	lastName = value;
}

void	Contact::setNickname(std::string value) {
	nickName = value;
}

void    Contact::setPhoneNumber(std::string value) {
	phoneNumber = value;
}

void	Contact::setDarkestSecret(std::string value) {
	darkestSecret = value;
}

std::string Contact::getFirstName(void) {
	return (firstName);
}

std::string Contact::getLastName(void) {
	return (lastName);
}

std::string Contact::getNickname(void) {
	return (nickName);
}

std::string Contact::getPhoneNumber(void) {
	return (phoneNumber);
}

std::string Contact::getDarkestSecret(void) {
	return (darkestSecret);
}

void	Contact::print()
{
	std::cout << "FirstName = " << getFirstName() << std::endl;	
	std::cout << "LastName = " << getLastName() << std::endl;	
	std::cout << "Nickname = " << getNickname() << std::endl;	
	std::cout << "PhoneNumber = " << getPhoneNumber() << std::endl;	
	std::cout << "DarkestSecret = " << getDarkestSecret() << std::endl;	
}