/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaiz <vaiz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 15:15:08 by odanyliu          #+#    #+#             */
/*   Updated: 2026/04/23 12:15:15 by vaiz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP
# include "AMateria.hpp"
# include <iostream>

class Ice : public virtual AMateria
{
	public:
		Ice(void);
		Ice(const Ice &other);
		Ice& operator=(const Ice &other);
		std::string const & getType() const; //Returns the materia type
		~Ice();
		Ice* clone() const;
		void use(ICharacter& target);
};

#endif