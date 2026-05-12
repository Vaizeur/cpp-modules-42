/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odanyliu <odanyliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 13:23:27 by odanyliu          #+#    #+#             */
/*   Updated: 2026/05/12 11:12:02 by odanyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>

class AAnimal
{
	protected:
		std::string _type;
	public:
		AAnimal(void);
		AAnimal(const AAnimal &other);
		AAnimal& operator=(const AAnimal &other);
		virtual ~AAnimal();
		virtual std::string getType(void) const;
		virtual void makeSound(void) const = 0;
		virtual void addIdea(std::string &value);
		virtual void printIdea(void) const;
};

#endif