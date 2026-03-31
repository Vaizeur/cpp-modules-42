/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odanyliu <odanyliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 14:23:40 by odanyliu          #+#    #+#             */
/*   Updated: 2026/02/24 14:54:18 by odanyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main(void)
{
	std::string A = "HI THIS IS BRAIN";
	std::string *stringPTR = &A;
	std::string &stringREF = A;

	std::cout << "the memory address of the string variable : (" << &A        << ")" << std::endl;
	std::cout << "The memory address held by stringPTR : (" 	 << stringPTR << ")" <<  std::endl;
	std::cout << "the memory address held by stringREF : (" 	 << &stringREF << ")" << std::endl;
	 
	std::cout << "The value of the string variable : (" 		<< A        << ")" << std::endl;
	std::cout << "The value pointed to by stringPTR : (" 	 	<< *stringPTR << ")" <<  std::endl;
	std::cout << "The value pointed to by stringREF : (" 	 << stringREF << ")" << std::endl;
	return 0;
}
