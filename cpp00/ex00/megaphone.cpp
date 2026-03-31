/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odanyliu <odanyliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 10:04:27 by odanyliu          #+#    #+#             */
/*   Updated: 2026/02/24 10:04:32 by odanyliu         ###   ########.fr       */
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
	std::string message = argv[1];
	std::string MESSAGE = argv[1];
	for (std::size_t i = 0; i < message.length(); i++)
        MESSAGE[i] = toupper(message[i]);
	std::cout << MESSAGE << std::endl;
	return 0;
}

