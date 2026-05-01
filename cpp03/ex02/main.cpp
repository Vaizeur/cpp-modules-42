/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odanyliu <odanyliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 10:31:15 by odanyliu          #+#    #+#             */
/*   Updated: 2026/05/01 10:17:27 by odanyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    std::cout << "\n===== CLAPTRAP TEST =====\n" << std::endl;

    ClapTrap a("CL4P");

    a.attack("enemy");
    a.takeDamage(5);
    a.beRepaired(3);
    a.attack("enemy2");


    std::cout << "\n===== SCAVTRAP TEST =====\n" << std::endl;

    ScavTrap b("SC4V");

    b.attack("target");
    b.takeDamage(30);
    b.beRepaired(10);
    b.guardGate();


    std::cout << "\n===== FRAGTRAP TEST =====\n" << std::endl;

    FragTrap c("FR4G");

    c.attack("monster");
    c.takeDamage(20);
    c.beRepaired(15);
    c.highFivesGuys();

    std::cout << "\n===== COPY TEST =====\n" << std::endl;

    FragTrap copy(c);
    copy.attack("copy_target");

    FragTrap assign("Temp");
    assign = c;
    assign.attack("assign_target");


    std::cout << "\n===== HEAP TEST =====\n" << std::endl;

    ClapTrap* h1 = new ClapTrap("HeapClap");
    ScavTrap* h2 = new ScavTrap("HeapScav");
    FragTrap* h3 = new FragTrap("HeapFrag");

    h1->attack("enemy");
    h2->attack("enemy");
    h3->attack("enemy");

    delete h1;
    delete h2;
    delete h3;

    std::cout << "\n===== ENERGY TEST =====\n" << std::endl;

    ClapTrap energy("Battery");

    for (int i = 0; i < 12; i++)
        energy.attack("dummy");
    std::cout << "\n===== DAMAGE TEST =====\n" << std::endl;

    ClapTrap dead("Zombie");

    dead.takeDamage(200);
    dead.attack("target");
    dead.beRepaired(10);

    std::cout << "\n===== END TEST =====\n" << std::endl;

    return 0;
}
