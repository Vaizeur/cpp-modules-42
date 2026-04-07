/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odanyliu <odanyliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 12:59:45 by odanyliu          #+#    #+#             */
/*   Updated: 2026/04/07 13:12:05 by odanyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Brain.hpp"

class Brain
{
	private:
		std::string ideas[100];
	public:
		Brain();
		Brain(Brain &other);
		Brain& operator=(Brain &other);
		~Brain();
};

Brain::Brain()
{
	std::cout << "Brain constructor" << std::endl;
}

Brain::Brain(Brain &other)
{
	std::cout << "Copy Brain constructor" << std::endl;
}

Brain& Brain::operator=(Brain &other)
{
	if (this == &other)
		return (*this);
	for (size_t i = 0; i < 100; i++)
		this->ideas[i] = other.ideas[i];
	return (*this);	
}

Brain::~Brain() {
	std::cout << "Brain destructor" << std::endl;
}