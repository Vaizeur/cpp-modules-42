/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odanyliu <odanyliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:52:51 by odanyliu          #+#    #+#             */
/*   Updated: 2026/04/02 09:33:38 by odanyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/phonebook.hpp"
#include <string>
#include <iostream>
#include <stdlib.h>
#include <sstream>

PhoneBook::PhoneBook()
{
	currentIndex = -1;
	total = 0;
}

void PhoneBook::addContact(std::string firstName, std::string lastName,
	std::string nickName, std::string phoneNumber, std::string darkestSecret)
{
	total++;
	currentIndex++;
	if (total > 8)
		total = 8;	
	if (currentIndex == 8)
		currentIndex = 0;
	contactList[currentIndex].setFirstName(firstName);
	contactList[currentIndex].setLastName(lastName);
	contactList[currentIndex].setNickname(nickName);
	contactList[currentIndex].setPhoneNumber(phoneNumber);
	contactList[currentIndex].setDarkestSecret(darkestSecret);
}

int	PhoneBook::readSingleInput(std::string &str,std::string inputName)
{
	while (true)
	{
		std::cout << inputName << " : ";
		std::getline(std::cin, str);	
		if (std::cin.eof())
			return (1);
		if (!str.empty())
			return (0);
	}
	return (0);	
}

void PhoneBook::read()
{
	std::string firstName, lastName, nickName, phoneNumber, darkestSecret;
	std::cout << "Veuillez saisir les informations du nouveau contact :" << std::endl;
	if (readSingleInput(firstName, "FirstName"))
		return ;
	if (readSingleInput(lastName, "LastName"))
		return ;
	if (readSingleInput(nickName, "NickName"))
		return ;
	if (readSingleInput(phoneNumber, "PhoneNumber"))
		return ;
	if (readSingleInput(darkestSecret, "DarkestSecret"))
		return ;
	addContact(firstName, lastName, nickName, phoneNumber, darkestSecret);
}

void	PhoneBook::printSingleValue(std::string value)
{
	std::string output;

	output = value.substr(0, 10);
	if (value.length() > 10)
		output[9] = '.';
	if (output.size() < 10)
        output.append(10 - output.size(), ' ');
	std::cout << output;
}

void	PhoneBook::search()
{
	std::cout << "INDEX    |FIRSTNAME |LASTNAME  |NICKNAME  |" << std::endl;
	for (int i = 0; i < total; i++)
	{
		std::cout << i << "        |";
		printSingleValue(contactList[i].getFirstName());
		std::cout << "|";
		printSingleValue(contactList[i].getLastName());
		std::cout << "|";
		printSingleValue(contactList[i].getNickname());
		std::cout << "|" << std::endl;
	}
	preciseSearch();
}

int		PhoneBook::preciseSearch()
{
	std::string	input;
	int			inputIndex;
	
	std::cout << "Veuillez saisir l'index pour en savoir plus : " << std::endl;
	std::getline(std::cin, input);
	std::stringstream ss(input);
	if (std::cin.eof())
		return (1);
	if (!(ss >> inputIndex)) {
		std::cout << "Index invalide !" << std::endl;
		return (1);
	}
	if (inputIndex < 0 || inputIndex >= total)
	{
		std::cout << "Index introuvable !" << std::endl;
		return (1);
	}
	contactList[inputIndex].print();
	return (0);
}