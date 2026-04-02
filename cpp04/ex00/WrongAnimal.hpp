/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odanyliu <odanyliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 13:23:27 by odanyliu          #+#    #+#             */
/*   Updated: 2026/04/02 15:12:16 by odanyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <iostream>

class WrongAnimal
{
	protected:
		std::string _type;
	public:
		WrongAnimal(void);
		WrongAnimal(WrongAnimal &other);
		WrongAnimal& operator=(WrongAnimal &other);
		~WrongAnimal();
		std::string getType(void) const;
		void makeSound(void) const;
};

#endif