/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odanyliu <odanyliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 13:23:27 by odanyliu          #+#    #+#             */
/*   Updated: 2026/04/07 12:54:14 by odanyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGDOG_HPP
# define WRONGDOG_HPP
# include <iostream>
# include "WrongAnimal.hpp"

class WrongDog : public WrongAnimal
{
	public:
		WrongDog(void);
		WrongDog(WrongDog &other);
		WrongDog& operator=(WrongDog &other);
		~WrongDog();
		void makeSound() const;
};

#endif