/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odanyliu <odanyliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 15:15:08 by odanyliu          #+#    #+#             */
/*   Updated: 2026/04/21 10:40:12 by odanyliu         ###   ########.fr       */
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
		Ice(Ice &other);
		Ice& operator=(Ice &other);
		std::string const & getType() const; //Returns the materia type
		~Ice();
		Ice* clone() const;
		void use(ICharacter& target);
};

#endif