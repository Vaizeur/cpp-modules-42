/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaiz <vaiz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:52:44 by odanyliu          #+#    #+#             */
/*   Updated: 2026/02/23 22:41:53 by vaiz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/contact.hpp"
#include "../includes/phonebook.hpp"

int main(void)
{
    PhoneBook phone;
    std::string input;

    while (true)
    {
        std::cout << "> ";
        if (!std::getline(std::cin, input))
            break;
        if (input == "EXIT")
            break;
        else if (input == "ADD")
            phone.read();
        else if (input == "SEARCH")
            phone.search();
        else
            std::cout << "Essayez 'ADD' 'SEARCH' ou 'EXIT'" << std::endl;
    }
}
