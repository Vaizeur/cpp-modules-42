/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaiz <vaiz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 11:25:10 by odanyliu          #+#    #+#             */
/*   Updated: 2026/04/23 15:10:22 by vaiz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AMateria.hpp"
#include "../includes/Ice.hpp"
#include "../includes/Cure.hpp"
#include "../includes/Character.hpp"
#include "../includes/MateriaSource.hpp"
#include <iostream>

void separator(std::string title)
{
	std::cout << "\n================ " << title << " ================\n";
}

int main()
{
	separator("Subject test");

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");
	ICharacter* bob = new Character("bob");

	AMateria* tmp;

	tmp = src->createMateria("ice");
	me->equip(tmp);

	tmp = src->createMateria("cure");
	me->equip(tmp);

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

	separator("Inventory limit");
	
	Character player("player");
	player.equip(new Ice());
	player.equip(new Ice());
	player.equip(new Cure());
	player.equip(new Cure());
	AMateria* extra = new Ice();
	player.equip(extra);
	delete extra;
	
	separator("Use invalid slots");

	Character mage("mage");
	mage.equip(new Ice());
	mage.use(0, mage);
	mage.use(1, mage);
	mage.use(-1, mage);
	mage.use(42, mage);
	
	separator("Unequip test");
	
	Character thief("thief");
	AMateria* ice = new Ice();
	thief.equip(ice);
	thief.use(0, thief);
	thief.unequip(0);
	
	std::cout << "After unequip" << std::endl;
	thief.use(0, thief);
	delete ice;
	
	separator("MateriaSource learning limit");
	
	MateriaSource source;
	source.learnMateria(new Ice());
	source.learnMateria(new Cure());
	source.learnMateria(new Ice());
	source.learnMateria(new Cure());

	AMateria* extraLearn = new Ice();
	source.learnMateria(extraLearn);
	delete extraLearn;
	
	separator("Create unknown materia");
	
	AMateria* unknown = source.createMateria("fire");
	if (!unknown)
		std::cout << "Unknown materia correctly returned NULL" << std::endl;

	separator("Deep copy constructor");
	
	Character original("original");
	original.equip(new Ice());
	original.equip(new Cure());
	Character copy(original);
	
	std::cout << "Original uses:" << std::endl;
	original.use(0, original);
	original.use(1, original);
	
	std::cout << "Copy uses:"  << std::endl;
	copy.use(0, copy);
	copy.use(1, copy);

	separator("Assignment operator");
	
	Character a("A");
	a.equip(new Ice());
	Character b("B");
	
	b = a;
	std::cout << "A uses:\n";
	a.use(0, a);
	std::cout << "B uses:\n";
	b.use(0, b);

	separator("Unequip cleanup test");

	Character test("cleanup");
	AMateria* m1 = new Ice();
	AMateria* m2 = new Cure();
	test.equip(m1);
	test.equip(m2);
	test.unequip(0);
	test.unequip(1);
	delete m1;
	delete m2;
	separator("End");
	return 0;
}