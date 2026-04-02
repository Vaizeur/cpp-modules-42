/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odanyliu <odanyliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 13:39:05 by odanyliu          #+#    #+#             */
/*   Updated: 2026/04/02 15:21:19 by odanyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete i;
	delete j;

	const WrongAnimal *meta_w = new WrongAnimal();
	const WrongAnimal *i_w = new WrongCat();
	std::cout << i_w->getType() << " " << std::endl;
	i_w->makeSound();
	meta_w->makeSound();

	delete meta_w;
	delete i_w;
	return (0);
}