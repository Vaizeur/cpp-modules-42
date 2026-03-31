/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileHandler.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odanyliu <odanyliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 16:35:27 by odanyliu          #+#    #+#             */
/*   Updated: 2026/02/25 09:41:33 by odanyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILEHANDLER_HPP
#define FILEHANDLER_HPP
#include <string>
#include <iostream>
#include <fstream>

class FileHandler
{
	private:
		std::string		fileName;
		std::ifstream	inputFile;
		std::ofstream	outputFile;
		void			replaceAllMatch(std::string line, std::string s1, std::string s2);
	public:
		FileHandler(std::string fileName);
		void    writeAndReplace(std::string s1,std::string s2);
		bool	openInFile();
		bool	openOutFile();
		void	close(int flag);
};

#endif