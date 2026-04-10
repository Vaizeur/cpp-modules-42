/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odanyliu <odanyliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 15:15:08 by odanyliu          #+#    #+#             */
/*   Updated: 2026/04/10 15:45:51 by odanyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# include "ICharacter.hpp"
# include <string>

class AMateria
{
	protected:
		std::string _type;
	public:
		AMateria(void);
		AMateria(AMateria &other);
		AMateria& operator=(AMateria &other);
		AMateria(std::string const & type);
		std::string const & getType() const;
		~AMateria();
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif