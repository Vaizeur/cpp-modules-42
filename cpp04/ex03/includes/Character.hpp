/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaiz <vaiz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 15:30:08 by odanyliu          #+#    #+#             */
/*   Updated: 2026/04/23 12:13:45 by vaiz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP
#include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
		std::string _name;
		AMateria	*_slot[4];
	public:
		Character(void);
		Character(std::string name);
		Character(const Character	&other);
		Character& operator=(const Character &other);
		
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
		
		~Character();
};


#endif