/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odanyliu <odanyliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 13:23:27 by odanyliu          #+#    #+#             */
/*   Updated: 2026/05/12 10:33:08 by odanyliu         ###   ########.fr       */
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
		WrongDog(const WrongDog &other);
		WrongDog& operator=(const WrongDog &other);
		~WrongDog();
		void makeSound() const;
};

#endif