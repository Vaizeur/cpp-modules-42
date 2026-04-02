/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odanyliu <odanyliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 10:04:27 by odanyliu          #+#    #+#             */
/*   Updated: 2026/04/02 09:26:01 by odanyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	std::string message;
	std::string MESSAGE;
	for (int i = 1; i < argc; i++)
	{
		message = argv[i];
		MESSAGE = argv[i];
		for (std::size_t y = 0; y < message.length(); y++)
			MESSAGE[y] = toupper(message[y]);
		std::cout << MESSAGE;
	}
	std::cout << std::endl;
	return 0;
}

