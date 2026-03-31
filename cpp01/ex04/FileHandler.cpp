/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileHandler.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odanyliu <odanyliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 16:35:27 by odanyliu          #+#    #+#             */
/*   Updated: 2026/02/25 09:40:00 by odanyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileHandler.hpp"

FileHandler::FileHandler(std::string fileName) :fileName(fileName) { }

bool FileHandler::openInFile()
{
	inputFile.open(fileName.c_str());
	if (inputFile.fail())
		return (false);
	return (true);
}

bool FileHandler::openOutFile()
{
	outputFile.open(fileName.append(".replace").c_str());
	if (outputFile.fail())
		return (false);
	return (true);
}

void FileHandler::replaceAllMatch(std::string line, std::string s1, std::string s2)
{
	size_t pos = 0;

	while ((pos = line.find(s1, pos)) != std::string::npos)
	{
		line.erase(pos, s1.length());
		line.insert(pos, s2);
		pos += s2.length();
	}
	outputFile << line;
}

void FileHandler::writeAndReplace(std::string s1,std::string s2)
{
	std::string line;

	while (std::getline(inputFile, line))
	{
		replaceAllMatch(line, s1, s2);
		outputFile << std::endl;
	}
}

void	FileHandler::close(int flag)
{
	if (flag == 0 || flag == 2)
		inputFile.close();
	if (flag == 1 || flag == 2)
		outputFile.close();
}