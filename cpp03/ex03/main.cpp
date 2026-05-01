/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odanyliu <odanyliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 10:31:15 by odanyliu          #+#    #+#             */
/*   Updated: 2026/05/01 10:15:44 by odanyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>
#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    std::cout << "===== STACK TEST =====" << std::endl;

    ClapTrap a("CL4P");
    ScavTrap b("SC4V");
    FragTrap c("FR4G");

    a.attack("enemy");
    a.takeDamage(5);
    a.beRepaired(3);

    std::cout << std::endl;

    b.attack("enemy");
    b.takeDamage(10);
    b.beRepaired(5);
    b.guardGate();

    std::cout << std::endl;

    c.attack("enemy");
    c.takeDamage(20);
    c.beRepaired(10);
    c.highFivesGuys();

    std::cout << std::endl;

    std::cout << "===== HEAP TEST =====" << std::endl;

    ClapTrap* h1 = new ClapTrap("HeapClap");
    ScavTrap* h2 = new ScavTrap("HeapScav");
    FragTrap* h3 = new FragTrap("HeapFrag");

    h1->attack("enemy");
    h2->attack("enemy");
    h3->attack("enemy");

    std::cout << std::endl;

    delete h1;
    delete h2;
    delete h3;

    std::cout << std::endl;

    std::cout << "===== POLYMORPHISM TEST =====" << std::endl;

    ClapTrap* p1 = new ScavTrap("PolyScav");
    ClapTrap* p2 = new FragTrap("PolyFrag");

    p1->attack("enemy");
    p2->attack("enemy");

    delete p1;
    delete p2;

    std::cout << std::endl;


    std::cout << "===== ARRAY HEAP TEST =====" << std::endl;

    ClapTrap* army[3];

    army[0] = new ClapTrap("Soldier1");
    army[1] = new ScavTrap("Soldier2");
    army[2] = new FragTrap("Soldier3");

    for (int i = 0; i < 3; i++)
        army[i]->attack("target");

    for (int i = 0; i < 3; i++)
        delete army[i];

    return 0;
}
