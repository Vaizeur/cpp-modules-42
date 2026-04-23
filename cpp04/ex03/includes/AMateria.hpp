/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaiz <vaiz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 15:15:08 by odanyliu          #+#    #+#             */
/*   Updated: 2026/04/23 12:15:58 by vaiz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# include "ICharacter.hpp"
# include <string>

class ICharacter;

class AMateria
{
	protected:
		std::string _type;
	public:
		AMateria(void);
		AMateria(const AMateria &other);
		AMateria& operator=(const AMateria &other);
		AMateria(std::string const & type);
		std::string const & getType() const;
		virtual ~AMateria();
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif