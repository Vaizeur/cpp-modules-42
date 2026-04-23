/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaiz <vaiz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 11:25:10 by odanyliu          #+#    #+#             */
/*   Updated: 2026/04/23 16:31:01 by vaiz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AMateria.hpp"
#include "../includes/Ice.hpp"
#include "../includes/Cure.hpp"
#include "../includes/Character.hpp"
#include "../includes/MateriaSource.hpp"
#include <iostream>

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

void subject_test()
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
}

void inventory_limit_test()
{
	separator("Inventory limit");

	Character player("player");
	player.equip(new Ice());
	player.equip(new Ice());
	player.equip(new Cure());
	player.equip(new Cure());

	AMateria* extra = new Ice();
	player.equip(extra);
	delete extra;
}

void invalid_slots_test()
{
	separator("Use invalid slots");

	Character mage("mage");
	mage.equip(new Ice());
	mage.use(0, mage);
	mage.use(1, mage);
	mage.use(-1, mage);
	mage.use(42, mage);
}

void unequip_test()
{
	separator("Unequip test");

	Character thief("thief");
	AMateria* ice = new Ice();
	thief.equip(ice);
	thief.use(0, thief);
	thief.unequip(0);

	std::cout << "After unequip:" << std::endl;
	thief.use(0, thief);
}

void materiasource_limit_test()
{
	separator("MateriaSource learning limit");

	MateriaSource source;
	source.learnMateria(new Ice());
	source.learnMateria(new Cure());
	source.learnMateria(new Ice());
	source.learnMateria(new Cure());

	AMateria* extraLearn = new Ice();
	source.learnMateria(extraLearn);
	delete extraLearn;
}

void unknown_materia_test()
{
	separator("Create unknown materia");

	MateriaSource source;
	AMateria* unknown = source.createMateria("fire");
	if (!unknown)
		std::cout << "Unknown materia correctly returned NULL" << std::endl;
}

void copy_constructor_test()
{
	separator("Deep copy constructor");
	
	Character original("original");
	original.equip(new Ice());
	original.equip(new Cure());

	Character copy(original);
	std::cout << "Original uses:" << std::endl;
	original.use(0, original);
	original.use(1, original);
	
	std::cout << "Copy uses:" << std::endl;
	copy.use(0, copy);
	copy.use(1, copy);
	
	std::cout << "\nRemoving materia from original...\n";
	original.unequip(0);
	std::cout << "Original after unequip:" << std::endl;
	original.use(0, original);
	std::cout << "Copy should still work:" << std::endl;
	copy.use(0, copy);
}

void assignment_operator_test()
{
	separator("Assignment operator");
	
	Character a("A");
	a.equip(new Ice());
	a.equip(new Cure());
	Character b("B");
	b = a;
	std::cout << "A uses:" << std::endl;
	a.use(0, a);
	a.use(1, a);
	std::cout << "B uses:" << std::endl;
	b.use(0, b);
	b.use(1, b);
	std::cout << "\nRemoving materia from A...\n";
	a.unequip(0);
	std::cout << "A after unequip:" << std::endl;
	a.use(0, a);
	std::cout << "B should still work:" << std::endl;
	b.use(0, b);
}

void unequip_cleanup_test()
{
	separator("Unequip cleanup test");

	Character test("cleanup");
	AMateria* m1 = new Ice();
	AMateria* m2 = new Cure();
	test.equip(m1);
	test.equip(m2);
	test.unequip(0);
	test.unequip(1);
}

int main(void)
{
	subject_test();
	inventory_limit_test();
	invalid_slots_test();
	unequip_test();
	materiasource_limit_test();
	unknown_materia_test();
	copy_constructor_test();
	assignment_operator_test();
	unequip_cleanup_test();
	separator("End");
	return 0;
}