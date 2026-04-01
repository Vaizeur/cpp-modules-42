/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odanyliu <odanyliu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 10:31:15 by odanyliu          #+#    #+#             */
/*   Updated: 2026/04/01 11:19:42 by odanyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main()
{
    std::cout << "---- CLAPTRAP TEST ----" << std::endl;

    ClapTrap a("lili");
    ClapTrap b("toto");

    a.attack("toto");
    b.takeDamage(3);
    b.beRepaired(2);

    b.attack("lili");
    a.takeDamage(4);
    a.beRepaired(1);

    std::cout << "\n---- SCAVTRAP TEST ----" << std::endl;

    ScavTrap c("protector");

    c.attack("lili");
    a.takeDamage(20);

    c.beRepaired(10);
    c.guardGate();

    std::cout << "\n---- ENERGY TEST ----" << std::endl;
    for (int i = 0; i < 50; i++)
        c.attack("toto");
    std::cout << "\n---- DAMAGE TEST ----" << std::endl;
    c.takeDamage(50);
    c.takeDamage(60);
    c.attack("lili");
    return 0;
}
