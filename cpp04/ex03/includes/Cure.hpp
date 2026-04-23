/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaiz <vaiz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 15:15:08 by odanyliu          #+#    #+#             */
/*   Updated: 2026/04/23 12:15:07 by vaiz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP
# include "AMateria.hpp"
# include <iostream>

class Cure : public virtual AMateria
{
	public:
		Cure(void);
		Cure(const Cure &other);
		Cure& operator=(const Cure &other);
		std::string const & getType() const;
		~Cure();
		Cure* clone() const;
		void use(ICharacter& target);
};

#endif