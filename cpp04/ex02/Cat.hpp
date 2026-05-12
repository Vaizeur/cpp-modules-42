/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odanyliu <odanyliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 13:23:27 by odanyliu          #+#    #+#             */
/*   Updated: 2026/05/12 11:14:38 by odanyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include <iostream>
# include "AAnimal.hpp"
# include "Brain.hpp"
class Cat : public AAnimal
{
	private :
		Brain *_brain;
	public:
		Cat(void);
		Cat(const Cat &other);
		Cat& operator=(const Cat &other);
		~Cat();
		void makeSound() const;

		void addIdea(std::string &value);
		void printIdea() const;	
};

#endif