/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odanyliu <odanyliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 09:40:33 by odanyliu          #+#    #+#             */
/*   Updated: 2026/04/21 11:35:00 by odanyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main(void)
{
	size_t count = 10;
	
	AAnimal** list = new AAnimal*[count];
	for (size_t i = 0; i < count / 2; i++)
		list[i] = new Dog();	
	for (size_t y = count / 2; y < count; y++)
		list[y] = new Cat();
	for (size_t x = 0; x < count; x++)
		delete list[x];
	delete [] list;
	return 0;
}
