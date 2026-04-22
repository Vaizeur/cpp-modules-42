/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odanyliu <odanyliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 15:30:08 by odanyliu          #+#    #+#             */
/*   Updated: 2026/04/21 11:29:31 by odanyliu         ###   ########.fr       */
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
		Character(Character	&other);
		Character& operator=(Character &other);
		
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
		
		~Character();
};


#endif