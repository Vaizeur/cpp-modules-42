/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odanyliu <odanyliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 12:59:45 by odanyliu          #+#    #+#             */
/*   Updated: 2026/05/12 11:15:58 by odanyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Brain.hpp"

Brain::Brain() : _ideasIdx(0)
{
	std::cout << "Brain constructor" << std::endl;
}

Brain::Brain(const Brain &other)
{
	_ideasIdx = other._ideasIdx;
	std::cout << "Copy Brain constructor" << std::endl;
	for (size_t i = 0; i < 100; i++)
		this->_ideas[i] = other._ideas[i];
}

Brain& Brain::operator=(const Brain &other)
{
	if (this == &other)
		return (*this);
	_ideasIdx = other._ideasIdx;
	for (size_t i = 0; i < 100; i++)
		this->_ideas[i] = other._ideas[i];
	return (*this);	
}

Brain::~Brain() {
	std::cout << "Brain destructor" << std::endl;
}

void Brain::addIdea(std::string &value)
{
	if (_ideasIdx >= 100)
		return ;
	_ideas[_ideasIdx] = value;
	_ideasIdx++;
}

void Brain::printIdea() const
{
	if (_ideasIdx == 0)
	{
		std::cout << "No ideas stored" << std::endl;
		return;
	}
	for (int i = 0; i < _ideasIdx; i++)
		std::cout << "Idea " << i << ": " << _ideas[i] << std::endl;
}