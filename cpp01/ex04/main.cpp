/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odanyliu <odanyliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 15:40:15 by odanyliu          #+#    #+#             */
/*   Updated: 2026/02/25 09:40:14 by odanyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileHandler.hpp"

int main(int argc, char const *argv[])
{
	if (argc != 4)
	{
		std::cout << "Invalid input" << std::endl;
		return (0);
	}
	std::string	file	= argv[1];
	std::string s1 		= argv[2];
	std::string s2		= argv[3];
	
	FileHandler handler(file);
	if(!handler.openInFile())
	{
		std::cout << "Error opening input file " << std::endl;
		return (0);		
	}
	if(!handler.openOutFile())
	{
		std::cout << "Error opening output file " << std::endl;
		handler.close(0);
		return (0);
	}
	handler.writeAndReplace(s1, s2);
	handler.close(2);
	return 0;
}
