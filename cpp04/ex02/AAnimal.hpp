/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odanyliu <odanyliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 13:23:27 by odanyliu          #+#    #+#             */
/*   Updated: 2026/04/10 14:49:40 by odanyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>

class AAnimal
{
	private:
		std::string _type;
	public:
		AAnimal(void);
		AAnimal(AAnimal &other);
		virtual AAnimal& operator=(AAnimal &other);
		virtual ~AAnimal();
		virtual std::string getType(void) const;
		virtual void makeSound(void) const = 0;
};

#endif