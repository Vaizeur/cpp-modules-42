/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odanyliu <odanyliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 10:31:15 by odanyliu          #+#    #+#             */
/*   Updated: 2026/05/01 10:19:15 by odanyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>
#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

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
    b.takeDamage(20);
    b.beRepaired(10);
    b.guardGate();


    std::cout << "\n===== COPY TEST =====\n" << std::endl;

    ScavTrap copy(b);
    copy.attack("copy_target");

    ScavTrap assign("Temp");
    assign = b;
    assign.attack("assign_target");


    std::cout << "\n===== HEAP TEST =====\n" << std::endl;

    ClapTrap* h1 = new ClapTrap("HeapClap");
    ScavTrap* h2 = new ScavTrap("HeapScav");

    h1->attack("enemy");
    h2->attack("enemy");

    delete h1;
    delete h2;


    std::cout << "\n===== ENERGY TEST =====\n" << std::endl;

    ClapTrap energy("Battery");
    for (int i = 0; i < 12; i++)
        energy.attack("dummy");
    std::cout << "\n===== DAMAGE TEST =====\n" << std::endl;

    ScavTrap dead("Guardian");

    dead.takeDamage(200);
    dead.attack("enemy");
    dead.guardGate();

    std::cout << "\n===== END TEST =====\n" << std::endl;
    return 0;
}
